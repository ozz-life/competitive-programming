func main() {
	digits := []int{1, 2, 3, 4, 5}
	for _, d := range digits {
		defer fmt.Println(d)
	}
}