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

func segmentLengths(numbers []int) (int, []int) {
	if len(numbers) == 0 {
		return 0, []int{}
	}

	segments := make([]int, 0) // Срез для хранения длин отрезков
	length := 1                // Начальная длина текущего отрезка
	maxValue := numbers[0]     // Максимальное значение в текущем отрезке

	// Обходим все числа в массиве, начиная со второго элемента
	for _, num := range numbers[1:] {
		// Если текущее число равно текущей длине отрезка, заканчиваем отрезок
		if length == maxValue {
			segments = append(segments, length)
			length = 1
			maxValue = num
		} else {
			// Если текущее число меньше или равно текущей длине отрезка,
			// заканчиваем отрезок и начинаем новый
			if num <= length {
				segments = append(segments, length)
				length = 1
				maxValue = num
			} else {
				length++
				maxValue = min(num, maxValue)
			}
		}
	}

	segments = append(segments, length)
	return len(segments), segments
}

func solve(in *bufio.Reader, out *bufio.Writer) {
	var n int
	fmt.Fscan(in, &n)

	numbers := make([]int, n)
	for j := 0; j < n; j++ {
		fmt.Fscan(in, &numbers[j])
	}

	k, segmentLengths := segmentLengths(numbers)
	fmt.Fprintln(out, k)
	for _, length := range segmentLengths {
		fmt.Fprint(out, length, " ")
	}
	fmt.Fprintln(out)
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
