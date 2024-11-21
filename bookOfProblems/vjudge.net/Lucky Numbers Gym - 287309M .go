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
	"sort"
	"strconv"
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

func IsLuckyNumber(s string) bool {
	for i := range s {
		if s[i] != '4' && s[i] != '7' {
			return false
		}
	}
	return true
}

func solve(in *bufio.Reader, out *bufio.Writer) {
	var a, b int64
	fmt.Fscan(in, &a, &b)

	var luckyNumbers []int64

	for i := a; i <= b; i++ {
		s := strconv.FormatInt(i, 10)
		if IsLuckyNumber(s) {
			luckyNumbers = append(luckyNumbers, i)
		}
	}

	// if len(luckyNumbers) == 0 {
	// 	fmt.Fprint(out, "-1")
	// } else {
	// 	for i, num := range luckyNumbers {
	// 		if i == len(luckyNumbers)-1 {
	// 			fmt.Fprintf(out, "%d", num)
	// 		} else {
	// 			fmt.Fprintf(out, "%d ", num)
	// 		}
	// 	}
	// }

	if len(luckyNumbers) == 0 {
		fmt.Fprint(out, "-1")
	} else {
		for _, num := range luckyNumbers {
			fmt.Fprintf(out, "%d ", num)

		}
	}
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
