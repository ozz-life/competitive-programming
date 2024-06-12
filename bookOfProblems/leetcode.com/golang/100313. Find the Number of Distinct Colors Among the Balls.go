package main

import (
	"fmt"
)

// func queryResults(limit int, queries [][]int) []int {
// 	ballColors := make(map[int]int)
// 	distinctColors := make(map[int]struct{})
// 	results := make([]int, len(queries))

// 	for i, query := range queries {
// 		ball, color := query[0], query[1]
		
// 		if prevColor, exists := ballColors[ball]; exists {
// 			delete(distinctColors, prevColor)
// 		}

// 		ballColors[ball] = color
// 		distinctColors[color] = struct{}{}

// 		for _, col := range ballColors {
// 			distinctColors[col] = struct{}{}
// 		}

// 		results[i] = len(distinctColors)
// 	}

// 	return results
// }

func queryResults(limit int, queries [][]int) []int {
	ballColors := make(map[int]int)
	colorCount := make(map[int]int)
	results := make([]int, len(queries))
	distinctCount := 0

	for i, query := range queries {
		ball, newColor := query[0], query[1]
		
		if oldColor, exists := ballColors[ball]; exists {
			colorCount[oldColor]--
			if colorCount[oldColor] == 0 {
				delete(colorCount, oldColor)
				distinctCount--
			}
		}

		ballColors[ball] = newColor
		if colorCount[newColor] == 0 {
			distinctCount++
		}
		colorCount[newColor]++

		results[i] = distinctCount
	}

	return results
}

func main() {
	limit := 4
	queries := [][]int{{1, 4}, {2, 5}, {1, 3}, {3, 4}}
	result := queryResults(limit, queries)
	fmt.Println(result) // Output: [1, 2, 2, 3]

	limit = 4
	queries = [][]int{{0, 1}, {1, 2}, {2, 2}, {3, 4}, {4, 5}}
	result = queryResults(limit, queries)
	fmt.Println(result) // Output: [1, 2, 2, 3, 4]
}