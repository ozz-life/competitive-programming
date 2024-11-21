#!/usr/bin/env bash

# Структура каталогов:
#
# ./b/main.go
# ./b/tests/
#  |----01
#  |----01.a
#  |----...
#  |----08
#  |----08.a
# ./c/main.go
# ./c/tests/
#  |----01
#  |----01.a
#  |----...
#
# After that run:
#  ./run_tests.sh ./b/main.go

COLOR_BLACK=0
COLOR_RED=1
COLOR_GREEN=2
COLOR_YELLOW=3
COLOR_GREY=8

reset_color="$(tput sgr0)"

source_file=${1:-main.go}

print_error() {
  local error_text="$1"
  local color_red="$(tput setaf $COLOR_RED)"
  echo "${color_red}ERROR: ${error_text}${reset_color}"
}

highlight () {
  local text="$1"
  local color="$2"
  local color_text="$(tput setab $color; tput setaf $COLOR_BLACK)"
  echo "${color_text} $text ${reset_color}"  
}

print_time () {
  local runtime=$1

  if (( $(echo "$runtime > 1000" | bc -l) )); then
    local color=$COLOR_RED
  elif (( $(echo "$runtime > 500" | bc -l) )); then
    local color=$COLOR_YELLOW
  else
    local color=$COLOR_GREY 
  fi

  local color_time="$(tput setaf $color)"
  local int_runtime=$(echo "$runtime * 1000" | awk '{print int($1)}')
  printf "${color_time}%dms${reset_color}" "$int_runtime"
}

clear_line () {
  tput cuu1
  tput el
}

if [ ! -f "$source_file" ]; then
  print_error "File '$source_file' does not exist"
  tput bel
  exit 1
fi

source_dir=$(dirname "$source_file")
source_filename=$(basename "$source_file")
tests_dir="$source_dir/tests"

if [ ! -d "$tests_dir" ]; then
  print_error "Tests directory does not exist"
  tput bel
  exit 1
fi

if ! which dos2unix &> /dev/null; then
  print_error "dos2unix not installed. Please install before running."
  tput bel
  exit 1
fi

for test_input in $(ls "$tests_dir" | sort -n)
do
  if [[ "$test_input" =~ ^([0-9]+)$ ]]; then
    test_num="${BASH_REMATCH[1]}"
    test_output="${tests_dir}/${test_num}.a"
    test_name="Test $test_num"

    echo "$(highlight "RUNS" $COLOR_YELLOW) $test_name"

    start_time=$(date +%s.%N)
    output=$(go run "$source_file" < "$tests_dir/$test_input" | dos2unix)
    end_time=$(date +%s.%N)
    runtime=$(echo "($end_time - $start_time) * 1000" | bc)

    clear_line

    expected_output=$(cat "$test_output" | dos2unix)
    if diff -Z -q <(echo "$output") <(echo "$expected_output") > /dev/null ; then 
      echo "$(highlight "PASS" $COLOR_GREEN) $test_name $(print_time $runtime)"
    else
      echo "$(highlight "FAIL" $COLOR_RED) $test_name"
      diff -Z -y --color=auto <(echo "$output") <(echo "$expected_output")
      exit 1
    fi
  fi
done