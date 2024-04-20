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
	X, Y int
}

func getResIJ(allPoints map[Point]bool, c1, c2 Point) (int, []Point) {
	res := 0
	var result []Point

	if !allPoints[c1] {
		res++
		result = append(result, c1)
	}

	if !allPoints[c2] {
		res++
		result = append(result, c2)
	}

	return res, result
}

func var1Circle(allPoints map[Point]bool, x1, y1, x2, y2 int) (int, []Point) {
	x11 := x1 + (y2 - y1)
	y11 := y1 - (x2 - x1)

	x22 := x2 + (y2 - y1)
	y22 := y2 - (x2 - x1)

	return getResIJ(allPoints, Point{x11, y11}, Point{x22, y22})
}

func var2Circle(allPoints map[Point]bool, x1, y1, x2, y2 int) (int, []Point) {
	x11 := x1 - (y2 - y1)
	y11 := y1 + (x2 - x1)

	x22 := x2 - (y2 - y1)
	y22 := y2 + (x2 - x1)

	return getResIJ(allPoints, Point{x11, y11}, Point{x22, y22})
}

func var3Circle(allPoints map[Point]bool, x1, y1, x2, y2 int) (int, []Point) {
	isCorrectInt := func(x int) bool {
		return x%2 == 0
	}

	var x11_2, y11_2, x22_2, y22_2 int

	if x1 < x2 {
		x11_2, y11_2 = (x1+x2)-int(math.Abs(float64(y2-y1))), (y1+y2)+int(math.Abs(float64(x2-x1)))

		x22_2, y22_2 = (x1+x2)+int(math.Abs(float64(y2-y1))), (y1+y2)-int(math.Abs(float64(x2-x1)))
	} else {
		x11_2, y11_2 = (x1+x2)-int(math.Abs(float64(y2-y1))), (y1+y2)-int(math.Abs(float64(x2-x1)))

		x22_2, y22_2 = (x1+x2)+int(math.Abs(float64(y2-y1))), (y1+y2)+int(math.Abs(float64(x2-x1)))
	}

	if isCorrectInt(x11_2) && isCorrectInt(y11_2) && isCorrectInt(x22_2) && isCorrectInt(y22_2) {
		return getResIJ(allPoints, Point{x11_2 / 2, y11_2 / 2}, Point{x22_2 / 2, y22_2 / 2})
	}

	return 0, nil
}

func solution(n int, table [][]int) (int, []Point) {
	if n == 0 {
		return 0, nil
	}

	if n == 1 {
		x, y := table[0][0], table[0][1]
		return 3, []Point{
			{X: x + 1, Y: y},
			{X: x, Y: y - 1},
			{X: x + 1, Y: y + 1},
		}
	}

	allPoints := make(map[Point]bool)
	res := 4
	var result []Point

	for i, p1 := range table[:len(table)-1] {
		for _, p2 := range table[i+1:] {
			resIJ, resultIJ := var1Circle(allPoints, p1[0], p1[1], p2[0], p2[1])
			if resIJ < res {
				res = resIJ
				result = resultIJ
			}

			resIJ, resultIJ = var2Circle(allPoints, p1[0], p1[1], p2[0], p2[1])
			if resIJ < res {
				res = resIJ
				result = resultIJ
			}

			resIJ, resultIJ = var3Circle(allPoints, p1[0], p1[1], p2[0], p2[1])
			if resIJ < res {
				res = resIJ
				result = resultIJ
			}

			if res == 0 {
				return res, result
			}
		}
	}

	return res, result
}

func solve(in *bufio.Reader, out *bufio.Writer) {
	// Read n
	var n int
	fmt.Fscan(in, &n)

	// Read table
	table := make([][]int, n)
	for i := 0; i < n; i++ {
		var x, y int
		fmt.Fscan(in, &x, &y)
		table[i] = []int{x, y}
	}

	// Call solution function
	res, result := solution(n, table)

	// Print results
	fmt.Fprintln(out, res)
	for _, point := range result {
		fmt.Fprintln(out, point.X, point.Y)
	}
}

// /*
//  * Main
//  ******************************************************************************/

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
