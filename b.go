package main

import (
	"fmt"
)

func main() {
	n := 4
	//pattern5(n)
	//pattern28(n)
	shape3(n)
}

func pattern5(n int) {
	for row := 1; row < 2*n; row++ {
		var totalColsInRow int

		if row < n {
			totalColsInRow = row
		} else {
			totalColsInRow = 2*n - row
		}
		
		for col := 1; col <= totalColsInRow; col++ {
			fmt.Print("* ")
		}
		fmt.Println()
	}
}


func pattern28(n int) {
	for row := 1; row < 2*n; row++ {
		var totalColsInRow int

		if row < n {
			totalColsInRow = row
		} else {
			totalColsInRow = 2*n - row
		}
		numberOfSpaces := n - totalColsInRow
		
		for s := 0; s < numberOfSpaces; s++ {
			fmt.Print(" ")
		}

		for col := 1; col <= totalColsInRow; col++ {
			fmt.Print("* ")
		}
		fmt.Println()
	}
}

// func shape3(n int) {
// 	for row := 1; row <= n; row++ {

// 		numberOfSpaces := n
		
// 		for s := 0; s < numberOfSpaces; s++ {
// 			fmt.Print(" ")
// 		}

// 		for col := 1; col <= 2 * row - 1; col++ {
// 			fmt.Print("*")
// 		}
// 		fmt.Println()
// 	}
// }


//    *
//   ***
//  *****
// *******
// Print a pyramid that has N rows.
func shape2(n int) {
	for row := 1; row <= n; row++ {
		for s := row; s < n; s++ {
			fmt.Print(" ")
		}
		for col := 1; col <= (2*row - 1); col++ {
			fmt.Print("*")
		}
		fmt.Println()
	}
}



//     *
//    ***
//   *****
//  *******
// *********
//  *******
//   *****
//    ***
//     *
func shape3(n int) {
	stars := 1
	spaces := n - 1

	for row := 1; row < n*2; row++ {
		for space := 1; space <= spaces; space++ {
			fmt.Print(" ")
		}

		for col := 1; col < stars*2; col++ {
			fmt.Print("*")
		}

		fmt.Println()

		if row < n {
			spaces--
			stars++
		} else {
			spaces++
			stars--
		}
	}
}

