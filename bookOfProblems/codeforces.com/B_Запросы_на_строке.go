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

/*
 * Solve
 ******************************************************************************/

func solve(in *bufio.Reader, out *bufio.Writer) {
	var s string
	fmt.Fscan(in, &s)
	var m int
	fmt.Fscan(in, &m)

	for i := 0; i < m; i++ {
		var l, r, k int
		fmt.Fscan(in, &l, &r, &k)

		l--         // Приведение индекса l к нулевой базе
		sz := r - l // Вычисление длины подстроки
		k %= sz     // Вычисление наименьшего количества позиций для циклического сдвига

		// s[:l] + s[r-k:r] + s[l:r-k] + s[r:]: Формируем новую строку, соединяя три части:
		// s[:l]: Строка от начала до индекса l, оставляем ее без изменений.
		// s[r-k:r]: Строка, которая сдвигается вправо, начиная с индекса r-k и до r.
		// s[l:r-k]: Строка, которая остается на месте после сдвига.
		// s[r:]: Строка от индекса r до конца, оставляем ее без изменений.

		s = s[:l] + s[r-k:r] + s[l:r-k] + s[r:] // Циклический сдвиг символов в подстроке s[l, r) на k позиций вправо

	}
	fmt.Println(s)
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
