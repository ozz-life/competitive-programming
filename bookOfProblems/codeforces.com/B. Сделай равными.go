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

/*
 * Solve
 ******************************************************************************/

func solve(in *bufio.Reader, out *bufio.Writer) {
	var n, sum int
	fmt.Fscan(in, &n)

	v := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &v[i])
		sum += v[i]
	}

	if sum%n != 0 {
		fmt.Println("NO")
		return
	}

	target := sum / n
	moves := 0

	for i := 0; i < n; i++ {
		if v[i] > target {
			diff := v[i] - target
			moves += diff
			v[i] -= diff
			if i+1 < n {
				v[i+1] += diff
			}
		}
	}

	possible := true
	for _, x := range v {
		if x != target {
			possible = false
			break
		}
	}

	if possible {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
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

	// var count_test int = 1;
	for i := 0; i < count_test; i++ {
		solve(in, out)
	}
}
