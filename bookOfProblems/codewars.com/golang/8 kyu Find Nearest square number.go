package kata

import "math"

func NearestSq(n int) int {
    root := int(math.Sqrt(float64(n)))
    
    lowerSquare := root * root
    upperSquare := (root + 1) * (root + 1)
    
    if n-lowerSquare < upperSquare-n {
        return lowerSquare
    }
    return upperSquare
}

////////////////////////////////////////////////////////////////////////////////

package kata

import (
	"math"
)

func NearestSq(n int) int {
	n = int(math.Round(math.Sqrt(float64(n))))

	return n * n
}