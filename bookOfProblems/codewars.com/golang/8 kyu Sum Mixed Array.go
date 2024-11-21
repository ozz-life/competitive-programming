package kata

import (
	"strconv"
)

func SumMix(arr []any) int {
	sum := 0

	for _, v := range arr {
		switch v := v.(type) {
		case int:
			sum += v
		case string:
			num, err := strconv.Atoi(v)
			if err == nil {
				sum += num
			}
		}
	}

	return sum
}

////////////////////////////////////////////////////////////////////////////////

package kata

import (
  "strconv"
  "fmt"
)

func SumMix(arr []any) int {
  sum := 0
  for _, v := range arr {
      iv, _ := strconv.Atoi(fmt.Sprintf("%v", v))
      sum += iv
  }
  return sum
}