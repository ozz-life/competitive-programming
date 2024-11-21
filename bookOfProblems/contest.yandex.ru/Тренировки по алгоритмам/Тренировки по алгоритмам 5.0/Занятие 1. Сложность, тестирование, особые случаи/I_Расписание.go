/*
            ▒█████  ▒███████▒▒███████▒      ██▓     ██▓  █████▒▓█████
           ▒██▒  ██▒▒ ▒ ▒ ▄▀░▒ ▒ ▒ ▄▀░     ▓██▒    ▓██▒▓██   ▒ ▓█   ▀
           ▒██░  ██▒░ ▒ ▄▀▒░ ░ ▒ ▄▀▒░      ▒██░    ▒██▒▒████ ░ ▒███
           ▒██   ██░  ▄▀▒   ░  ▄▀▒   ░     ▒██░    ░██░░▓█▒  ░ ▒▓█  ▄
           ░ ████▓▒░▒███████▒▒███████▒ ██▓ ░██████▒░██░░▒█░    ░▒████▒
           ░ ▒░▒░▒░ ░▒▒ ▓░▒░▒░▒▒ ▓░▒░▒ ▒▓▒ ░ ▒░▓  ░░▓   ▒ ░    ░░ ▒░ ░
             ░ ▒ ▒░ ░░▒ ▒ ░ ▒░░▒ ▒ ░ ▒ ░▒  ░ ░ ▒  ░ ▒ ░ ░       ░ ░  ░
           ░ ░ ░ ▒  ░ ░ ░ ░ ░░ ░ ░ ░ ░ ░     ░ ░    ▒ ░ ░ ░       ░
               ░ ░    ░ ░      ░ ░      ░      ░  ░ ░             ░  ░
                    ░        ░          ░
          Author: Stanislav "ozz" Ozeransky | Site: https:://ozz.life/

We are what we think.
All that we are arises with our thoughts.
With our thoughts we make the world.
Speak or act with a pure mind
And happiness will follow you
As your shadow, unshakable. ― Gautama Buddha

*/

package main

import (
	"bufio"
	"fmt"
	"os"
)

/*
 * Math
 ******************************************************************************/

func gcd(a, b int) int {
	for a != 0 {
		a, b = b%a, a
	}
	return b
}
func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
func min(a, b int) int {
	if b < a {
		return b
	}
	return a
}
func max(a, b int) int {
	if b > a {
		return b
	}
	return a
}

/*
 * Solve
 ******************************************************************************/

func isLeapYear(year int) bool {
	return (year%400 == 0) || (year%4 == 0 && year%100 != 0)
}

// getMonthDays возвращает количество дней в месяце для указанного года и месяца.
func getMonthDays(year, month int) int {
	monthDays := [12]int{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
	if month == 2 && isLeapYear(year) {
		return 29
	}
	return monthDays[month-1]
}

// getWeekdayIndex возвращает индекс дня недели по его названию.
func getWeekdayIndex(weekday string) int {
	weekdays := [...]string{"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"}
	for i, w := range weekdays {
		if w == weekday {
			return i
		}
	}
	return -1
}

func solve(in *bufio.Reader, out *bufio.Writer) {
	var n, year int
	fmt.Fscanln(in, &n)
	fmt.Fscanln(in, &year)

	holidays := make(map[string]bool)
	for i := 0; i < n; i++ {
		var day int
		var month string
		fmt.Fscanln(in, &day, &month)
		holidays[fmt.Sprintf("%d %s", day, month)] = true
	}

	var firstDayOfWeek string
	fmt.Fscanln(in, &firstDayOfWeek)

	monthsnames := [...]string{
		"January",
		"February",
		"March",
		"April",
		"May",
		"June",
		"July",
		"August",
		"September",
		"October",
		"November",
		"December",
	}

	weekdays := [...]string{"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"}
	firstWeekdayIndex := getWeekdayIndex(firstDayOfWeek)

	dayCounts := make(map[int]int)
	holidayCounts := make(map[int]int)

	day := 1
	month := 1

	for i := 0; i < 365+map[bool]int{false: 0, true: 1}[isLeapYear(year)]; i++ {
		dayCounts[firstWeekdayIndex]++
		if holidays[fmt.Sprintf("%d %s", day, monthsnames[month-1])] {
			holidayCounts[firstWeekdayIndex]++
		}

		firstWeekdayIndex = (firstWeekdayIndex + 1) % 7
		day++
		if day > getMonthDays(year, month) {
			month++
			day = 1
		}
	}

	minDays := 54
	maxDays := -1
	bestDayOfWeek := ""
	worstDayOfWeek := ""

	for i, dayCount := range dayCounts {
		dayCount -= holidayCounts[i]
		if dayCount < minDays {
			minDays = dayCount
			worstDayOfWeek = weekdays[i]
		}
		if dayCount > maxDays {
			maxDays = dayCount
			bestDayOfWeek = weekdays[i]
		}
	}

	fmt.Fprintln(out, bestDayOfWeek, worstDayOfWeek)
}

/*
 * Main
 ******************************************************************************/

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	// var count_test int
	// fmt.Fscan(in, &count_test)

	var count_test int = 1
	for i := 0; i < count_test; i++ {
		solve(in, out)
	}
}
