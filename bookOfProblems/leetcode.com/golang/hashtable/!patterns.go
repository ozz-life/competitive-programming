//////// frequencyMap

// 1. Frequency Counting
// Pattern Overview:

// This pattern involves counting the frequency of elements in an array or a
// string using a hashtable. It's useful for finding duplicates or determining
// the most occurring element.
// https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/description/

func smallerNumbersThanCurrent(nums []int) []int {
	frequencyMap := make(map[int]int)

	for _, num := range nums {
		frequencyMap[num]++
	}

	result := make([]int, len(nums))

	for i, num := range nums {
		count := 0
		for k, v := range frequencyMap {
			if k < num {
				count += v
			}
		}
		result[i] = count
	}

	return result
}

///////////////////////////////
// 2. Паттерн "Pair Summing" (Суммирование пар)
// Описание паттерна:
// Этот паттерн можно обобщить для любого случая поиска пар, которые суммируются до заданного значения.
// https://leetcode.com/problems/two-sum/description/

func twoSum(nums []int, target int) []int {
	hash := make(map[int]int)

	for i, num := range nums {
		complement := target - num

		if index, ok := hash[complement]; ok {
			return []int{index, i}
		}

		hash[num] = i
	}

	return nil
}

///////////////////////////////////

// 3. Subarray Sum or "Sum Frequencies" or Cumulative Sum
// Pattern Overview:
// This pattern involves finding subarrays whose elements sum up to a target value.
// It's crucial for solving problems related to dynamic programming and sliding window techniques.
// ОЧЕНЬ ПОДРОБНО: https://leetcode.com/problems/subarray-sum-equals-k/solutions/4772278/general-approach-for-subarray-problems/

// https://leetcode.com/problems/subarray-sum-equals-k/description/
// https://leetcode.com/problems/subarray-sum-equals-k/editorial/ ТАМ ЕСТЬ АНИМАЦИЯ!
// Подробная статья по решению https://hashnode.com/post/subarray-sum-equals-k-ckod8z19l0bbofqs1god753rz
// 560 - Важно, т.к могут быть минусовые значения на сумме, sliding window невозможен.
// sliding window works horrible with negative numbers
// Examples with some negative numbers will help
// Array isn't sorted, so there's no correct way to move the pointers
// ВАЖНО

// "the total number of continuous subarrays" means how many numbers in subarrays which Sum is K
// , but this questions really meaning is how many subarrays which sum is K
// After I carefully read the questions, I found a "s" in word "subarrays"
// "contiguous" means consecutive elements. However, when you see the passing solutions
// , the question wants simply "subarray", and contiguous is not enforced in test cases.

//current cumulative sum - k

// A basic problem on cumulative sum, difference of cumulative sum and hashMap pattern (hashMap if input array has negative elements, hashSet if positive elements).
// Problems with this pattern:

// https://leetcode.com/problems/subarray-sum-equals-k/
// https://leetcode.com/problems/continuous-subarray-sum/
// https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/
// Problems sharing similarity in question framing:

// https://leetcode.com/problems/minimum-size-subarray-sum/ (only +ve elements): different from above pattern problems, where we are maximising the subArray size so repetitions on cumulativeSums occur, whereas in this problem we are minimizing the size of candidate so sliding becomes handy.
// https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/ (contains -ve elements): uses monotonic deque

// Same as (with a slight modification)
// https://leetcode.com/problems/contiguous-array/description/
// https://leetcode.com/problems/subarray-sum-equals-k/description/
// https://leetcode.com/problems/subarrays-with-k-different-integers/description/
// https://leetcode.com/problems/count-number-of-nice-subarrays/description/
// https://leetcode.com/problems/binary-subarrays-with-sum/description/
// https://leetcode.com/problems/subarray-product-less-than-k/description/
// https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/description/
// Please upvote (only if you feel helpful) , so others could also see this !

// To use sliding window, given startIndex and endIndex you must be able to tell if all of the elements will not be used again, before expand or shrink the window. This is not the case here, where one element can be used again, in different subsets.
// Number_of_Submatrix <-- Next Level of this problem as recommended....!
// https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/description/

func subarraySum(nums []int, k int) int {

	m := make(map[int]int)
	m[0] = 1

	out, sum := 0, 0

	for _, v := range nums {
		sum += v
		prefix := sum - k

		if v, ok := m[prefix]; ok {
			out += v
		}
		m[sum]++
	}

	return out
}

func subarraySum(nums []int, k int) int {
	m := make(map[int]int)
	m[0] = 1
	ans, sum := 0, 0
	for _, v := range nums {
		sum += v
		ans += m[sum-k]
		m[sum]++

	}
	return ans
}

////////////////////////////////////////////////////////////////////////////////
// 4. Group Anagram
// Further, we can again optimize this solution by using a frequency array of each
// of the string which will have a O(K) time complexity which is better as compared
// to sorting the string which takes O(KlogK) time complexity.

// {
// 	"aet": ["eat", "tea", "ate"],
// 	"ant": ["tan", "nat"],
// 	"abt": ["bat"]
//  }

func groupAnagrams(strs []string) [][]string {
	anagramMap := make(map[string][]string)

	for _, word := range strs {
		sortedWord := sortString(word)

		if group, found := anagramMap[sortedWord]; found {
			anagramMap[sortedWord] = append(group, word)
		} else {
			anagramMap[sortedWord] = []string{word}
		}
	}

	var result [][]string
	for _, group := range anagramMap {
		result = append(result, group)
	}

	return result
}

func sortString(s string) string {
	characters := []rune(s)
	sort.Slice(characters, func(i, j int) bool {
		return characters[i] < characters[j]
	})
	return string(characters)
}

///////////////////////////

func groupAnagrams(strs []string) [][]string {
	hash := make(map[string][]string)
	for _, str := range strs {
		key := get_key(str)
		arr, exists := hash[key]
		if !exists {
			hash[key] = make([]string, 0)
		}
		hash[key] = append(arr, str)
	}
	answer := make([][]string, 0)
	for _, val := range hash {
		answer = append(answer, val)
	}
	return answer
}

func get_key(str string) string {
	counter := make([]int, 26)
	for _, char := range str {
		counter[int(char)-97] += 1
	}
	answer := make([]string, len(counter))
	for i, number := range counter {
		answer[i] = strconv.Itoa(number)
	}
	return strings.Join(answer, ".")
}

/////////////////////////////

func sortString(s string) string {
	runes := []rune(s)
	sort.Slice(runes, func(i, j int) bool { return runes[i] < runes[j] })
	return string(runes)
}

func groupAnagrams(strs []string) [][]string {
	anagrams := make(map[string][]string)

	for _, str := range strs {
		sortedStr := sortString(str)
		anagrams[sortedStr] = append(anagrams[sortedStr], str)
	}

	var result [][]string
	for _, group := range anagrams {
		result = append(result, group)
	}

	return result
}

////////////////////////////////

func groupAnagrams(strs []string) [][]string {
	result := make([][]string, 0)
	group := make(map[string][]string)

	for _, w := range strs {
		s := []rune(w)
		sort.Slice(s, func(i, j int) bool { return s[i] < s[j] })
		group[string(s)] = append(group[string(s)], w)
	}

	for _, V := range group {
		result = append(result, V)
	}

	return result
}

////////////////////////////////////

func groupAnagrams(strs []string) [][]string {
	mapIndex := make(map[int][]string)
	for _, v := range strs {
		occurance := getOccuranceArray(v)
		hashCode := getHashCode(occurance)
		if arr, ok := mapIndex[hashCode]; ok {
			mapIndex[hashCode] = append(arr, v)
		} else {
			mapIndex[hashCode] = []string{v}
		}
	}
	ans := make([][]string, 0)
	for _, v := range mapIndex {
		ans = append(ans, v)
	}
	return ans
}

func getOccuranceArray(word string) []int {
	arr := make([]int, 26)
	for _, v := range word {
		arr[v-'a']++
	}
	return arr
}

func getHashCode(occurances []int) int {
	hashCode := 64
	for _, v := range occurances {
		hashCode = 31*hashCode + v
	}
	return hashCode
}

////////////////////////////////////////

func groupAnagrams(strs []string) [][]string {
	m := make(map[[26]int]int)

	res := make([][]string, 0)

	for _, str := range strs {
		tmp := [26]int{}
		for _, r := range str {
			tmp[r-'a']++
		}
		if _, ok := m[tmp]; !ok {
			m[tmp] = len(res)
			res = append(res, []string{})
		}
		res[m[tmp]] = append(res[m[tmp]], str)

	}

	return res
}

////////////////////////////////////////////

func sortString(s string) string {
	r := []rune(s)
	sort.Slice(r, func(i, j int) bool {
		return r[i] < r[j]
	})
	return string(r)
}

func groupAnagrams(strs []string) [][]string {
	mp := make(map[string][]string)

	for _, str := range strs {
		sortedStr := sortString(str)
		mp[sortedStr] = append(mp[sortedStr], str)
	}

	var ans [][]string
	for _, group := range mp {
		ans = append(ans, group)
	}

	return ans
}

////////////////////////////////////////////
