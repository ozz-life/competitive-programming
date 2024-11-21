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
	"math"
	"os"
	"sort"
	"strings"
	"unicode"
)

type Integer interface {
	int | int8 | int16 | int32 | int64 | uint | uint8 | uint16 | uint32 | uint64
}

/*
 * Common
 ******************************************************************************/

// swap(&a, &b)
func Swap[T any](a, b *T) {
	temp := *a
	*a = *b
	*b = temp
}

func SortIntsAsc(a []int) {
	sort.Ints(a)
}

func SortIntsDesc(a []int) {
	sort.Slice(a, func(i, j int) bool {
		return a[i] > a[j]
	})
}

func SortStringsAsc(a []string) {
	sort.Strings(a)
}

func SortStringsDesc(a []string) {
	sort.Slice(a, func(i, j int) bool {
		return a[i] > a[j]
	})
}

func LowerBound(a []int, x int) int {
	l := -1     // a[l] < x
	r := len(a) // a[r] >= x
	for r > l+1 {
		m := l + (r-l)>>1 // m > l, m < r
		if a[m] < x {
			l = m
		} else {
			r = m
		}
	}
	return r
}

func UpperBound(a []int, x int) int {
	l := -1     // a[l] <= x
	r := len(a) // a[r] > x
	for r > l+1 {
		m := l + (r-l)>>1 // m > l, m < r
		if a[m] <= x {
			l = m
		} else {
			r = m
		}
	}
	return l
}

func IsOdd[T Integer](x T) bool {
	return x&1 != 0
}

func IsEven[T Integer](x T) bool {
	return x&1 == 0
}

/*
 * Math
 ******************************************************************************/

func MathGcd[T Integer](a, b T) T {
	for b > 0 {
		a %= b
		a, b = b, a
	}
	return a
}

func MathLcm[T Integer](a, b T) T {
	return a / MathGcd(a, b) * b
}

func MathAbs[T Integer](x T) T {
	if x < 0 {
		return -x
	}
	return x
}

func MathPow(base, exp float64) float64 {
	return math.Log(base) * exp
}

func MathSumOfDigitsInteger[T Integer](n T) T {
	var sum T = 0
	for n > 0 {
		sum += n % 10
		n /= 10
	}
	return sum
}

func MathSumOfDigitsString(s string) int {
	sum := 0
	for _, r := range s {
		sum += int(r - '0')
	}
	return sum
}

// binpow calculates a^n % mod using iterative binary exponentiation.
// https://cp-algorithms.com/algebra/binary-exp.html
func BinaryExponentiation(base, exponent, mod int64) int64 {
	result := int64(1)
	for exponent > 0 {
		if exponent&1 == 1 {
			result = (result * base) % mod
		}
		base = (base * base) % mod
		exponent >>= 1
	}
	return result
}

func MathIntegerDivisionCeil[T Integer](numerator, denominator T) T {
	if numerator == 0 {
		return 0
	}
	return (numerator-1)/denominator + 1
}

/*
 * Array
 ******************************************************************************/

func ArrayMin[T Integer](arr []T) (min T, minIndex int) {
	if len(arr) == 0 {
		fmt.Println("Error: func ArrayMin. len(arr) == 0")
		return 0, -1
	}

	min = arr[0]
	minIndex = 0

	for i := 1; i < len(arr); i++ {
		if arr[i] < min {
			min = arr[i]
			minIndex = i
		}
	}

	return min, minIndex
}

func ArrayMax[T Integer](arr []T) (max T, maxIndex int) {
	if len(arr) == 0 {
		fmt.Println("Error: func ArrayMax. len(arr) == 0")
		return 0, -1
	}

	max = arr[0]
	maxIndex = 0

	for i := 1; i < len(arr); i++ {
		if arr[i] > max {
			max = arr[i]
			maxIndex = i
		}
	}

	return max, maxIndex
}

func ArrayReverse[T any](arr []T, start, end int) {
	for start < end {
		arr[start], arr[end] = arr[end], arr[start]
		start++
		end--
	}
}

func ArraySum[T Integer](arr []T, start, end int) T {
	var sum T = 0
	for start < end {
		sum += arr[start]
		start++
	}
	return sum
}

/*
 * String
 ******************************************************************************/

func CharIsLetter(c rune) bool {
	return unicode.IsLetter(c)
}

func CharIsVowel(c rune) bool {
	switch unicode.ToLower(c) {
	case 'a', 'e', 'i', 'o', 'u':
		return true
	}
	return false
}

func StringIsPalindrome(s string) bool {
	l, r := 0, len(s)-1
	for l < r {
		if s[l] != s[r] {
			return false
		}
		l++
		r--
	}
	return true
}

func StringSumOfDigits(s string) int {
	sum := 0
	for _, r := range s {
		sum += int(r - '0')
	}
	return sum
}

func StringFilterAlphanumeric(s string) string {
	var sb strings.Builder
	for _, r := range s {
		if unicode.IsLetter(r) || unicode.IsDigit(r) {
			sb.WriteRune(r)
		}
	}
	return sb.String()
}

func StringAddLeadingZeros(s string, n int) string {
	if n <= 0 {
		return s
	}
	return strings.Repeat("0", n) + s
}

func StringRemoveLeadingZeros(s string) string {
	i := 0
	for i < len(s) && s[i] == '0' {
		i++
	}
	return s[i:]
}

/*
 * Solve
 ******************************************************************************/

// A
// func solve(in *bufio.Reader, out *bufio.Writer) {
// 	var n, k int // >=k Забирает ВСЁ
// 	fmt.Fscan(in, &n, &k)
// 	a := make([]int, n)
// 	for i := range a {
// 		fmt.Fscan(in, &a[i])
// 	}

// 	// Встречает последовательно
// 	var capital int = 0

// 	var ans int
// 	for i := range a {
// 		if a[i] >= k {
// 			capital += a[i]
// 		}
// 		if a[i] == 0 && capital > 0 {
// 			capital -= 1
// 			ans++
// 		}
// 	}

// 	fmt.Fprintln(out, ans)
// }

// B. Робин Гуд и Большой Дуб
func solve(in *bufio.Reader, out *bufio.Writer) {
	var n, k int // год и время сколько листья остаются
	fmt.Fscan(in, &n, &k)

	fmt.Fprintln(out, n)

	//lists := MathPow(float64(n), float64(n))

}

// C. Робин Гуд в городе
// func solve(in *bufio.Reader, out *bufio.Writer) {
// 	var n int 
// 	fmt.Fscan(in, &n)
// 	a := make([]int, n)
// 	for i := range a {
// 		fmt.Fscan(in, &a[i])
// 	}
	
// 	mx, mxIdx := ArrayMax(a)
	

// }

/*
 * Main
 ******************************************************************************/

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var count_test int
	fmt.Fscan(in, &count_test)

	//var count_test int = 1
	for i := 0; i < count_test; i++ {
		solve(in, out)
	}
}
