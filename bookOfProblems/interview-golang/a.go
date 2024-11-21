package main

import "fmt"

type A string

func (a *A) String() string {
  return "$" + string(*a)
}

func main() {
  a := A("x")
  fmt.Println("{" + a + "}")
  
  fmt.Println(a.String())
}

// Выведет: ${x}