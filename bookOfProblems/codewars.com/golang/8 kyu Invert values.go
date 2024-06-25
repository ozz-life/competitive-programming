package kata


func Invert(arr []int) []int {
  newArr := make([]int, len(arr))
  
  for idx, value := range arr {
      newArr[idx] = value * -1
  }
  
  return newArr
}

////////////////////////////////////////////////////////////////////////////////

package kata


func Invert(arr []int) (result []int) {
  for _, i := range arr {
    result = append(result, -i)
  }
  return
}