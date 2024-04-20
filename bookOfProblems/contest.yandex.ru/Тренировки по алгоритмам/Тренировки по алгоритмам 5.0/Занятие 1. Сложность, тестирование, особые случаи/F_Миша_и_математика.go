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
	"strings"
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

func isOdd(num int) bool {
	return num%2 != 0
}

func isEven(num int) bool {
	return num%2 == 0
}

/*
 * Solve
 ******************************************************************************/

// E*E=E
// E+E=E
// E*O=E
// E+O=O
// O*O=O
// O+O=E
// O*E=E
// O+E=O

// func solve(in *bufio.Reader, out *bufio.Writer) {
// 	var n int
// 	fmt.Fscanln(in, &n)
// 	a := make([]int, n)
// 	for i := 0; i < n; i++ {
// 		fmt.Fscan(in, &a[i])
// 	}

// 	var odd bool = false
// 	var idxCase int
// 	oddIdx := len(a)

// 	for i := 0; i < len(a)-1 && !odd; i++ {
// 		if isEven(a[i]) && isEven(a[i+1]) {
// 			fmt.Fprint(out, "+")
// 		} else if isOdd(a[i]) && isOdd(a[i+1]) {
// 			odd = true
// 			oddIdx = i
// 			idxCase = 0
// 			fmt.Fprint(out, "x")
// 		} else if isEven(a[i]) && isOdd(a[i+1]) {
// 			odd = true
// 			oddIdx = i + 1
// 			idxCase = 0
// 			fmt.Fprint(out, "+")
// 		} else if isOdd(a[i]) && isEven(a[i+1]) {
// 			odd = true
// 			oddIdx = i
// 			idxCase = 1
// 			fmt.Fprint(out, "+")
// 		}
// 	}

// 	switch idxCase {
// 	case 0:
// 		for i := oddIdx; i < len(a)-1; i++ {
// 			if oddIdx == 0 && i == oddIdx {
// 				continue
// 			}
// 			if isOdd(a[i+1]) {
// 				fmt.Fprint(out, "x")
// 			} else if isEven(a[i+1]) {
// 				fmt.Fprint(out, "+")
// 			}
// 		}
// 	case 1:
// 		for i := oddIdx; i < len(a)-1; i++ {
// 			if oddIdx == 0 && i == oddIdx {
// 				continue
// 			}
// 			fmt.Fprint(out, "x")
// 		}
// 	}
// }

func solve(in *bufio.Reader, out *bufio.Writer) {
	var n int
	fmt.Fscanln(in, &n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
	}

	ans := make([]string, 0)
	state := "no_odd_summand"

	for _, num := range a {
		switch state {
		case "no_odd_summand":
			if num%2 == 0 {
				ans = append(ans, "+")
			} else {
				state = "last_odd"
			}
		case "last_odd":
			if num%2 == 0 {
				ans = append(ans, "+")
				state = "multiply_even"
			} else {
				ans = append(ans, "x")
			}
		case "multiply_even":
			ans = append(ans, "x")
		}
	}

	result := strings.Join(ans, "")
	fmt.Fprint(out, result)
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
