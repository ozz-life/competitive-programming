package main

import (
  "fmt"
  "strconv"
  "unsafe"
)

func main() {
  a := []int{1, 2, 3}
  fmt.Println("a := []int{1, 2, 3}")
  print("a", a)
  fmt.Println("------------------------")

  b := a
  fmt.Println("b := a")
  print("a", a)
  print("b", b)
  fmt.Println("------------------------")

  b = append(b, 4)
  fmt.Println("b = append(b, 4)")
  print("a", a)
  print("b", b)
  fmt.Println("------------------------")

  c := b
  fmt.Println("c := b")
  print("a", a)
  print("b", b)
  print("c", c)
  fmt.Println("------------------------")

  b[0] = 0
  fmt.Println("b[0] = 0")
  print("a", a)
  print("b", b)
  print("c", c)
  fmt.Println("------------------------")

  e := append(c, 5)
  fmt.Println("e := append(c, 5)")
  print("a", a)
  print("b", b)
  print("c", c)
  print("e", e)
  fmt.Println("------------------------")

  b[2] = 7
  fmt.Println("b[2] = 7")
  print("a", a)
  print("b", b)
  print("c", c)
  print("e", e)
  fmt.Println("------------------------")

  fmt.Println(a, b, c, e)
}

func print(name string, slice []int) {
  baseArrayPtr := getBaseArrayPtr(slice)

  sliceText := getSliceAsText(slice)

  fmt.Printf("%v  %s = %v   len: %d, cap: %d \n", baseArrayPtr, name, sliceText, len(slice), cap(slice))
}

func getBaseArrayPtr(slice []int) unsafe.Pointer {
  type sliceType struct {
    ptr unsafe.Pointer
    len uint64
    cap uint64
  }

  ptr := (*sliceType)(unsafe.Pointer(&slice)).ptr
  return ptr
}

func getSliceAsText(slice []int) string {
  sliceText := "["

  array := slice[:cap(slice)]

  for i, element := range array {
    if i != 0 {
      sliceText += " "
    }

    sliceText += strconv.Itoa(element)

    if i+1 == len(slice) {
      sliceText += " |"
    }
  }

  sliceText += "]"
  
  return sliceText
}