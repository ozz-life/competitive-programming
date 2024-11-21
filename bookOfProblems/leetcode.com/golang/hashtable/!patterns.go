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
// 4. Group Anagram https://leetcode.com/problems/group-anagrams/description/
// Pattern Overview:
// This pattern involves grouping anagrams together. It's useful for problems where you need to categorize words based on their character composition.
// Further, we can again optimize this solution by using a frequency array of each
// of the string which will have a O(K) time complexity which is better as compared
// to sorting the string which takes O(KlogK) time complexity.

// {
// 	"aet": ["eat", "tea", "ate"],
// 	"ant": ["tan", "nat"],
// 	"abt": ["bat"]
//  }

// Canonical?

func groupAnagrams(strs []string) [][]string {
	anagramMap := make(map[string][]string)

	for _, word := range strs {
		sortedWord := sortString(word)
		anagramMap[sortedWord] = append(anagramMap[sortedWord], word)
	}

	result := make([][]string, 0, len(anagramMap))
	for _, group := range anagramMap {
		result = append(result, group)
	}

	return result
}

func sortString(s string) string {
	runes := []rune(s)
	sort.Slice(runes, func(i, j int) bool {
		return runes[i] < runes[j]
	})
	return string(runes)
}

///////////////////////////

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

////////////////////////////////////////////////////////////////////////////////
// 5. Longest Consecutive Sequence

// Pattern Overview:
// This pattern involves finding the longest consecutive sequence of elements in
// an array. It's crucial for problems related to sequence and set operations.

// Example Problem:
// Leetcode Problem 128 - Longest Consecutive Sequence

// Another really good example is 'montonic stack' questions such
// as https://leetcode.com/problems/next-greater-element-ii/, which also has
// a loop inside a loop but has TC of O(2N).

// red-black tree
// disjoint set function of Ackermann

// Use a hash map to store boundary information of consecutive sequence for each element;
// there are 4 cases when a new element i reached:
// neither i+1 nor i-1 has been seen: m[i]=1;
// both i+1 and i-1 have been seen: extend m[i+m[i+1]] and m[i-m[i-1]] to each other;
// only i+1 has been seen: extend m[i+m[i+1]] and m[i] to each other;
// only i-1 has been seen: extend m[i-m[i-1]] and m[i] to each other.

// If the unordered_map m doesnot contain i, m[i] will return 0
// This rule means, if there is no i + 1 in m(Case3), the assignment sentences
// turns out to be
// r = max(r, m[i] = m[i + 0] = m[i - m[i - 1]] = m[i + 0] + m[i - 1] + 1);
//More concisely, it's
//r = max(r, m[i] = m[i] = m[i - m[i - 1]] = m[i - 1] + 1);.
// We can analysis case1, case2 and case4 in a similar way.

// Step1: neither i+1 nor i-1 has been seen: m[i]=1;
// Explanation: current value is not in any sequence so far, so it's sequence of 1

// Step2: both i+1 and i-1 have been seen: extend m[i+m[i+1]] and m[i-m[i-1]] to each other;
// Explanation: current value is in middle of sequence, so it could union left sequence and right sequence. New sequence size is size(left_sequence) + 1 + size(right_sequence)
// After we calculate the size of new sequence, we need to update upperbound and lowerbound of sequence
// Why we should update upperbound and lowerbound of sequence? To sequence become bigger when we union, we only check lowerbound and upperbound

// Step3: only i+1 has been seen: extend m[i+m[i+1]] and m[i] to each other;
// Same explanation as Step2

// Step4: only i-1 has been seen: extend m[i-m[i-1]] and m[i] to each other.
// Same explanation as Step2

func longestConsecutive(nums []int) int {
	m := make(map[int]int)
	r := 0

	for _, num := range nums {
		if m[num] > 0 {
			continue
		}
		left, right := m[num-1], m[num+1]
		length := left + right + 1
		m[num] = length
		m[num-left] = length
		m[num+right] = length
		if length > r {
			r = length
		}
	}

	return r
}

// Whenever a new element n is inserted into the map, do two things:

// See if n - 1 and n + 1 exist in the map, and if so, it means there is an existing sequence next to n. Variables left and right will be the length of those two sequences, while 0 means there is no sequence and n will be the boundary point later. Store (left + right + 1) as the associated value to key n into the map.
// Use left and right to locate the other end of the sequences to the left and right of n respectively, and replace the value with the new length.
// Everything inside the for loop is O(1) so the total time is O(n).

func longestConsecutive(nums []int) int {
	m := make(map[int]int)
	res := 0

	for _, n := range nums {
		if _, exists := m[n]; !exists {
			left := 0
			if val, ok := m[n-1]; ok {
				left = val
			}
			right := 0
			if val, ok := m[n+1]; ok {
				right = val
			}
			// sum: length of the sequence n is in
			sum := left + right + 1
			m[n] = sum

			// keep track of the max length
			if sum > res {
				res = sum
			}

			// extend the length to the boundary(s)
			// of the sequence
			// will do nothing if n has no neighbors
			m[n-left] = sum
			m[n+right] = sum
		}
	}

	return res
}
