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

type Point struct {
	x, y int
}

func FindLeftMost(points []Point) Point {
	leftMost := points[0]
	for _, p := range points {
		if p.x < leftMost.x {
			leftMost = p
		}
	}
	return leftMost
}

func FindRightMost(points []Point) Point {
	rightMost := points[0]
	for _, p := range points {
		if p.x > rightMost.x {
			rightMost = p
		}
	}
	return rightMost
}

func FindLowest(points []Point) Point {
	lowest := points[0]
	for _, p := range points {
		if p.y < lowest.y {
			lowest = p
		}
	}
	return lowest
}

func FindHighest(points []Point) Point {
	highest := points[0]
	for _, p := range points {
		if p.y > highest.y {
			highest = p
		}
	}
	return highest
}

func solve(in *bufio.Reader, out *bufio.Writer) {
	var k int
	fmt.Fscanln(in, &k)

	points := make([]Point, k)
	for i := 0; i < k; i++ {
		var x, y int
		fmt.Fscanf(in, "%d %d\n", &x, &y)
		points[i] = Point{x, y}
	}

	leftMost := FindLeftMost(points)
	rightMost := FindRightMost(points)
	lowest := FindLowest(points)
	highest := FindHighest(points)

	leftBottomX := min(leftMost.x, lowest.x)
	leftBottomY := min(leftMost.y, lowest.y)
	rightTopX := max(rightMost.x, highest.x)
	rightTopY := max(leftMost.y, highest.y)

	fmt.Fprintf(out, "%d %d %d %d\n", leftBottomX, leftBottomY, rightTopX, rightTopY)
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
