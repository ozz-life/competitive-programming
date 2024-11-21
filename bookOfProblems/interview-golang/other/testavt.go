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
	"encoding/json"
	"fmt"
	"os"
	"sort"
	"strings"
	"unicode"
)

/*
 * Common
 ******************************************************************************/

// Передаём адреса. swap(&a, &b)
func swap(a *int, b *int) {
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

/*
 * Math
 ******************************************************************************/

func gcd(a, b int) int {
	for b > 0 {
		a %= b
		a, b = b, a
		//swap(&a, &b)
	}
	return a
}

func lcm(a, b int) int {
	return a / gcd(a, b) * b
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func min[T int | string](a, b T) T {
	if b < a {
		return b
	}
	return a
}

func max[T int | string](a, b T) T {
	if b > a {
		return b
	}
	return a
}

func sumOfDigits(n int) int {
	sum := 0
	for n > 0 {
		sum += n % 10
		n /= 10
	}
	return sum
}

func sumOfDigitsString(s string) int {
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

func ArrayMinMax(arr []int) (int, int) {
	var min, max int
	var n = len(arr)

	if n%2 == 0 {
		if arr[0] > arr[1] {
			max = arr[0]
			min = arr[1]
		} else {
			min = arr[0]
			max = arr[1]
		}
	} else {
		min = arr[0]
		max = arr[0]
	}

	for i := 2; i < n-1; i += 2 {
		if arr[i] > arr[i+1] {
			if arr[i] > max {
				max = arr[i]
			}
			if arr[i+1] < min {
				min = arr[i+1]
			}
		} else {
			if arr[i+1] > max {
				max = arr[i+1]
			}
			if arr[i] < min {
				min = arr[i]
			}
		}
	}

	return min, max
}

func ArrayReverse(arr []int, start, end int) {
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

func Foo() error {
	var err *os.PathError = nil
	return err
}

// func solve(in *bufio.Reader, out *bufio.Writer) {
// 	err := Foo()
// 	fmt.Println(err)
// 	fmt.Println(err == nil)
// }

// const (
// 	a = iota + 3
// 	_
// 	b
// 	c
// )

// func solve(in *bufio.Reader, out *bufio.Writer) {
// 	fmt.Println(b)
// }

// func solve(in *bufio.Reader, out *bufio.Writer) {
// 	arr := []string{"o", "a", "p"}
// 	val:= arr[3]

// 	fmt.Println(val)
// }

// func solve(in *bufio.Reader, out *bufio.Writer) {
// 	m := map[string]bool{
// 		"a": true,
// 		"b": false,
// 		"c": true,
// 	}
// 	val := m["a"]
// 	fmt.Println(val)
// }

// func solve(in *bufio.Reader, out *bufio.Writer) {
// 	a := make([]int, 0, 3)
// 	a = append(a, 1, 2)
// 	b := a[0:2]
// 	b[0] = 3
// 	fmt.Println(a)
// }

// func A() {
// 	defer B()
// 	C()
// }

// func solve(in *bufio.Reader, out *bufio.Writer) {
// 	var a int64
// 	defer fmt.Print(a)
// 	defer func() {
// 		fmt.Print(a)
// 	}()

// 	a = 1
// }

// func change(a *int) {
// 	t := *a * 2
// 	a = &t
// }

// func solve(in *bufio.Reader, out *bufio.Writer) {
// 	a := 3
// 	change(&a)
// 	fmt.Println(a)
// }

// func solve(in *bufio.Reader, out *bufio.Writer) {
// 	tasks := make(chan int)
// 	tasks <- 1
// 	tasks <- 2

// 	fmt.Println(tasks)
// }

type Model struct {
	Name string `json:"test"`
	Age  int    `json:"age"`
}

func solve(in *bufio.Reader, out *bufio.Writer) {
	data := `{"name":"Alex", "age":30}`
	var model Model
	err := json.Unmarshal([]byte(data), &model)
	if err != nil {
		fmt.Println("Error")
		return
	}
	fmt.Println(model)
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
