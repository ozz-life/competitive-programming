package main

import (
	"fmt"
	"unsafe"
)

func print[T any](name string, slice []T) {  
    baseArrayPtr := getBaseArrayPtr(slice)  
  
    sliceText := getSliceAsText(slice)  
  
    //fmt.Printf("%v  %s = %v   len: %d, cap: %d \n", baseArrayPtr, name, sliceText, len(slice), cap(slice))  
	fmt.Printf("%d  %s = %v   len: %d, cap: %d \n", baseArrayPtr, name, sliceText, len(slice), cap(slice))  

}  
  
type sliceType struct {  
    ptr unsafe.Pointer  
    len uint64  
    cap uint64  
}  
  
func getBaseArrayPtr[T any](slice []T) unsafe.Pointer {  
    ptr := (*sliceType)(unsafe.Pointer(&slice)).ptr  
    return ptr  
}  
  
func getSliceAsText[T any](slice []T) string {  
    sliceText := "["  
  
    array := slice[:cap(slice)]  
  
    for i, element := range array {  
       if i != 0 {  
          sliceText += " "  
       }  
  
       sliceText += fmt.Sprintf("%v", element)  
  
       if i+1 == len(slice) {  
          sliceText += " |"  
       }  
    }  
  
    sliceText += "]"  
  
    return sliceText  
}

func main() {
	a := []byte{'a', 'b', 'c'} // abc l3 = c3
	print("a", a)
	b := append(a[1:2], 'd')   // B NEW bd
	print("b", b)
	b[0] = 'z'                 // zd

	fmt.Println()
	print("a", a)
	print("b", b)
	fmt.Printf("a[0]: %p b[0]: %p\n", &a[0], &b[0])
}
