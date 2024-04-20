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

func solve(in *bufio.Reader, out *bufio.Writer) {
	var n1, n2, n3 int
	fmt.Fscan(in, &n1)
	m1 := make(map[int]bool)
	for i := 0; i < n1; i++ {
		var x int
		fmt.Fscan(in, &x)
		m1[x] = true
	}

	fmt.Fscan(in, &n2)
	m2 := make(map[int]bool)
	for i := 0; i < n2; i++ {
		var x int
		fmt.Fscan(in, &x)
		m2[x] = true
	}

	fmt.Fscan(in, &n3)
	m3 := make(map[int]bool)
	for i := 0; i < n3; i++ {
		var x int
		fmt.Fscan(in, &x)
		m3[x] = true
	}

	result := make([]int, 0)
	for num := range m1 {
		if m2[num] || m3[num] {
			result = append(result, num)
		}
	}
	for num := range m2 {
		if m1[num] && !contains(result, num) {
			result = append(result, num)
		} else if m3[num] && !contains(result, num) {
			result = append(result, num)
		}
	}
	for num := range m3 {
		if m1[num] && !contains(result, num) {
			result = append(result, num)
		} else if m2[num] && !contains(result, num) {
			result = append(result, num)
		}
	}

	sort.Ints(result)
	for i, num := range result {
		if i != 0 {
			fmt.Fprint(out, " ")
		}
		fmt.Fprint(out, num)
	}
}

func contains(arr []int, num int) bool {
	for _, n := range arr {
		if n == num {
			return true
		}
	}
	return false
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
