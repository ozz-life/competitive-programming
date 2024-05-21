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
 * Common
 ******************************************************************************/

// Передаём адреса. swap(&a, &b)
func swap(a *int, b *int) {
	temp := *a
	*a = *b
	*b = temp
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

/*
 * Solve
 ******************************************************************************/

func check(x, y byte) bool {
	delta := abs(int(x) - int(y))
	return delta == 0 || delta == 2
}

// func solve(in *bufio.Reader, out *bufio.Writer) {
// 	var n int
// 	var s string
// 	fmt.Fscan(in, &n, &s)

// 	var ok bool = true
// 	for i := 0; i < n / 2; i++ {
// 		var k int = abs(int(s[i]) - int(s[n - i - 1]))
// 		if k > 2 || k % 2 == 1 {
// 			ok = false
// 			break
// 		}
// 	}

// 	if ok {
// 		fmt.Fprintln(out, "YES")
// 	} else {
// 		fmt.Fprintln(out, "NO")
// 	}
// }

func solve(in *bufio.Reader, out *bufio.Writer) {
	var n int
	var s string
	fmt.Fscan(in, &n, &s)

	var ok bool = true
	for i := 0; i < n/2; i++ {
		ok = check(s[i], s[n-i-1])
		if !ok {
			break
		}
	}

	if ok {
		fmt.Fprintln(out, "YES")
	} else {
		fmt.Fprintln(out, "NO")
	}
}

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
