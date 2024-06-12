// Pattern 1. SlidingWindowBestState

windowBest := 0
windowStart, windowEnd := 0, 0
for windowEnd; windowEnd < N; windowEnd++ {
	// состояние валидное.
	// Обновляем состояние окна указателем windowEnd
	// for (windowNotValid) {
	// - Обновляем windowBest
	// (¯`·._.··¸.-~*´¨¯¨`*·~-.,-( Движение окна )-,.-~*´¨¯¨`*·~-.¸··._.·´¯)
	// - Мы делаем сужение, shrink окна до того момента, пока вновь не будет valid
	// - Удаляем элемент windowStart
	// - Добавляем элемент windowEnd
	// } // Теперь состояние снова валидное
// По завершению обновляем bestещё раз
}

unordered_map<char, int> counts; // Frequencies of chars in the window
int res = 0;
int windowStart = 0;
for(int windowEnd = 0; windowEnd < s.length(); windowEnd++){
	counts[s[windowEnd]]++; // Add right pointer to window 

	while(counts[s[windowEnd]] > 1){ // While the element at right pointer created a repeat
		counts[s[windewStart++]] --; // While condition not valid, remove element at left pointer from window by decreasing its count, and then increment left pointer. In this case, it is while s[j] is a duplicate (we will stop after removing the duplicate copy of s[j]).
	} // Now the condition is valid
	res = max(res, j-i+1); // Update global max with the length of current valid substring
}
return res;


///////////////////////


func fn(arr []int) int {

	ans, curr := 0, 0
    for l, r := 0; r < len(nums); r++ {
        // do logic here to add arr[right] to curr

        for WINDOW_CONDITION_BROKEN {
            // remove arr[left] from curr
            l++
        }

        // update ans
    }

    return ans
}