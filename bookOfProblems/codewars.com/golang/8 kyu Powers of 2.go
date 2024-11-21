package kata

func PowersOfTwo(n int) []uint64 {
    powers := make([]uint64, n+1)

    for i := 0; i <= n; i++ {
        powers[i] = 1 << uint64(i)
    }

    return powers
}

////////////////////////////////////////////////////////////////////////////////

package kata

import (
	"math"
)

func PowersOfTwo(n int) (powers []uint64) {
	for i := 0; i <= n; i++ {
		powers = append(powers, uint64(math.Pow(2, float64(i))))
	}
	return
}

////////////////////////////////////////////////////////////////////////////////

package kata

func PowersOfTwo(n int) (arr []uint64) {
  for i := 0; i <= n; i++ {
    arr = append(arr, 1 << i)
  }
  return
}