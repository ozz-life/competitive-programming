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
	"unicode"
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
	Row int
	Col int
}

var directions = map[rune][]Point{
	'R': {{0, 1}, {1, 0}, {0, -1}, {-1, 0}},   // Направления для ладьи
	'B': {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}}, // Направления для слона
}

func isBlocked(grid [][]rune, point Point, char rune) bool {
	// Проверяем, не находится ли точка за пределами доски
	if point.Row < 0 || point.Row >= len(grid) || point.Col < 0 || point.Col >= len(grid[0]) {
		return false
	}

	// Проверяем, не пустая ли клетка
	if grid[point.Row][point.Col] != '*' && grid[point.Row][point.Col] != '0' {
		return true
	}

	return false
}

func checkAttack(grid [][]rune, letters []struct {
	char rune
	row  int
	col  int
}) {
	for _, letter := range letters {
		direction := directions[letter.char] // Получаем направления для текущей фигуры
		for _, dir := range direction {
			next := Point{letter.row + dir.Row, letter.col + dir.Col} // Вычисляем следующую точку в направлении dir
			// Пока не упрётся в другую фигуру или не выйдет за пределы доски, помечаем клетки как битые
			for next.Row >= 0 && next.Row < len(grid) && next.Col >= 0 && next.Col < len(grid[0]) && !isBlocked(grid, next, letter.char) {
				grid[next.Row][next.Col] = '0'
				next.Row += dir.Row // Переходим к следующей клетке в направлении dir
				next.Col += dir.Col
			}
		}
	}
}

func countStars(grid [][]rune) int {
	count := 0
	for _, row := range grid {
		for _, cell := range row {
			if cell == '*' {
				count++
			}
		}
	}
	return count
}

func solve(in *bufio.Reader, out *bufio.Writer) {
	var grid [][]rune
	var letters []struct {
		char rune // Тип фигуры ('R' - ладья, 'B' - слон)
		row  int
		col  int
	}

	for i := 0; i < 8; i++ {
		line, _, _ := in.ReadLine()
		row := []rune(string(line))
		grid = append(grid, row)

		for j, char := range row {
			if unicode.IsLetter(char) {
				letters = append(letters, struct {
					char rune
					row  int
					col  int
				}{char, i, j})
			}
		}
	}

	// fmt.Println("Actual grid size:", len(grid), "x", len(grid[0]))
	// Проверяем корректность размера сетки
	if len(grid) != 8 || len(grid[0]) != 8 {
		//fmt.Println("Error: Invalid grid size")
		fmt.Println("0")
		return
	}

	checkAttack(grid, letters)
	starsLeft := countStars(grid)
	fmt.Println(starsLeft)

	// Выводим состояние доски и расположение фигур
	// for _, row := range grid {
	// 	fmt.Println(string(row))
	// }
	// fmt.Println("Letters:")
	// for _, letter := range letters {
	// 	fmt.Printf("Letter: %c, Row: %d, Col: %d\n", letter.char, letter.row, letter.col)
	// }
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
