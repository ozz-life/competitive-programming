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

/*
 * Common
 ******************************************************************************/

// Передаём адреса. swap(&a, &b)
func Swap(a *int, b *int) {
	temp := *a
	*a = *b
	*b = temp
}

// Сортировка целых чисел по возрастанию
func SortIntsAsc(a []int) {
	sort.Ints(a)
}

// Сортировка целых чисел по убыванию
func SortIntsDesc(a []int) {
	sort.Slice(a, func(i, j int) bool {
		return a[i] > a[j]
	})
}

// Сортировка строк по возрастанию
func SortStringsAsc(a []string) {
	sort.Strings(a)
}

// Сортировка строк по убыванию
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

func IsOdd(x int) bool {
	return x&1 != 0
}

func IsEven(x int) bool {
	return x&1 == 0
}

/*
 * Math
 ******************************************************************************/

func Gcd(a, b int) int {
	for b > 0 {
		a %= b
		a, b = b, a
	}
	return a
}

func Lcm(a, b int) int {
	return a / Gcd(a, b) * b
}

func Abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func Pow(x int, y int) int {
	result := 1
	for i := 0; i < y; i++ {
		result *= x
	}
	return result
}

func SumOfDigits(n int) int {
	sum := 0
	for n > 0 {
		sum += n % 10
		n /= 10
	}
	return sum
}

func SumOfDigitsString(s string) int {
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

func IntegerDivisionCeil(numerator, denominator int) int {
	return (numerator-1)/denominator + 1
}

/*
 * Array
 ******************************************************************************/

func ArrayReverse[T any](arr []T, start, end int) {
	for start < end {
		arr[start], arr[end] = arr[end], arr[start]
		start++
		end--
	}
}

func ArraySum(arr []int, start, end int) int {
	sum := 0
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

// WA10
// func solve(in *bufio.Reader, out *bufio.Writer) {
// 	var a, b, c, d int64
// 	fmt.Fscan(in, &a, &b, &c, &d)

// 	if (a<<b)-1 > (c<<d)-1 {
// 		fmt.Fprintln(out, "YES")
// 	} else {
// 		fmt.Fprintln(out, "NO")
// 	}
// }

// WA 12
// func solve(in *bufio.Reader, out *bufio.Writer) {
// 	var a, b, c, d int64
// 	fmt.Fscan(in, &a, &b, &c, &d)

// 	if int64(math.Pow(float64(a), float64(b))) > int64(math.Pow(float64(c), float64(d))) {
// 		fmt.Fprintln(out, "YES")
// 	} else {
// 		fmt.Fprintln(out, "NO")
// 	}
// }

// AC

func PowLog(base, exp float64) float64 {
	return math.Log(base) * exp
}

func solve(in *bufio.Reader, out *bufio.Writer) {
	var a, b, c, d float64
	fmt.Fscan(in, &a, &b, &c, &d)

	// left := float64(b) * math.Log(float64(a))
	// right := float64(d) * math.Log(float64(c))

	left := PowLog(a, b)
	right := PowLog(c, d)

	if left > right {
		fmt.Fprintln(out, "YES")
	} else {
		fmt.Fprintln(out, "NO")
	}
}

// Wrong answer on test 12
// func Power(a, b int64) int64 {
// 	result := int64(1)
// 	for b > 0 {
// 		if b&1 == 1 {
// 			result *= a
// 		}
// 		a *= a
// 		b >>= 1
// 	}
// 	return result
// }

// func solve(in *bufio.Reader, out *bufio.Writer) {
// 	var a, b, c, d int64
// 	fmt.Fscan(in, &a, &b, &c, &d)

// 	if Power(a, b) > Power(c, d) {
// 		fmt.Fprintln(out, "YES")
// 	} else {
// 		fmt.Fprintln(out, "NO")
// 	}
// }

// ///////////////////////////////////////////////////////////////////////////
// WA12
// func Ipow(base, exp int) int {
// 	result := 1
// 	for {
// 		if exp&1 == 1 {
// 			result *= base
// 		}
// 		exp >>= 1
// 		if exp == 0 {
// 			break
// 		}
// 		base *= base
// 	}
// 	return result
// }

// func solve(in *bufio.Reader, out *bufio.Writer) {
// 	var a, b, c, d int
// 	fmt.Fscan(in, &a, &b, &c, &d)

// 	if Ipow(a, b) > Ipow(c, d) {
// 		fmt.Fprintln(out, "YES")
// 	} else {
// 		fmt.Fprintln(out, "NO")
// 	}
// }

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
