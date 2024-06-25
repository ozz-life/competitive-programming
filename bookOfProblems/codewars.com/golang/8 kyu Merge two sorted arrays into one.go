package kata

import "sort"

func MergeArrays(arr1, arr2 []int) []int {
    sort.Ints(arr1)
    sort.Ints(arr2)
    
    merged := make([]int, 0, len(arr1) + len(arr2))
    i, j := 0, 0
    for i < len(arr1) && j < len(arr2) {
        if arr1[i] < arr2[j] {
            merged = append(merged, arr1[i])
            i++
        } else if arr1[i] > arr2[j] {
            merged = append(merged, arr2[j])
            j++
        } else {
            merged = append(merged, arr1[i])
            i++
            j++
        }
    }

    for i < len(arr1) {
        merged = append(merged, arr1[i])
        i++
    }
    for j < len(arr2) {
        merged = append(merged, arr2[j])
        j++
    }


    if len(merged) == 0 {
        return merged
    }
  
    result := []int{merged[0]}
  
    for k := 1; k < len(merged); k++ {
        if merged[k] != merged[k-1] {
            result = append(result, merged[k])
        }
    }
  
    return result
}

////////////////////////////////////////////////////////////////////////////////

