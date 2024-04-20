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

// arrowValue определяет число, на которое указывает стрелка
func arrowValue(segments []int, speed, slowdown float64) int {
	index := int((speed-0.001)/slowdown) % len(segments)
	length := len(segments)
	value1 := segments[index]
	value2 := segments[(length-index)%length]
	if value1 > value2 {
		return value1
	}
	return value2
}

// maxWinnings определяет максимальный выигрыш при вращении колеса
func maxWinnings(segments []int, minSpeed, maxSpeed int, slowdown float64) int {
	maxWinnings := 0
	for speed := minSpeed; speed <= maxSpeed; speed += int(slowdown) {
		winnings := arrowValue(segments, float64(speed), slowdown)
		if maxWinnings < winnings {
			maxWinnings = winnings
		}
	}
	return maxWinnings
}

func solve(in *bufio.Reader, out *bufio.Writer) {
	var n, minSpeed, maxSpeed int
	var slowdown float64
	fmt.Fscan(in, &n)
	segments := make([]int, n)
	for i := range segments {
		fmt.Fscan(in, &segments[i])
	}
	fmt.Fscan(in, &minSpeed, &maxSpeed, &slowdown)

	ans := maxWinnings(segments, minSpeed, maxSpeed, slowdown)
	fmt.Fprint(out, ans)
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
