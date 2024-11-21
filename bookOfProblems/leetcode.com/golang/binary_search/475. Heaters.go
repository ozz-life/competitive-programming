//1. Наивный алгоритм

func findRadius(houses []int, heaters []int) int {
	ans := 0
	for _, house := range houses {
		minDist := math.MaxInt32
		for _, heater := range heaters {
			dist := abs(heater - house)
			minDist = min(minDist, dist)
		}
		ans = max(ans, minDist)
	}
	return ans
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

// 2. Бинарный поиск. Отсортируем и lower_bound - первый >=
// O(heaters.size + houses.size) * log(heaters.size))

func findRadius(houses []int, heaters []int) int {
	if len(heaters) == 0 {
		fmt.Println("Ошибка: слайс heaters пустой")
	}
	
	sort.Ints(heaters)

	l := -1
	r := len(heaters)
	for r - l > 1 {
		m := l + (r - l) >> 1
		if {

		} else {

		}
	}


}
