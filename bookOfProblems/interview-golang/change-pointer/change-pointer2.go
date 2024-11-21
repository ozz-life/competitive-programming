// package main

// import "fmt"

// type Person struct {
// 	Name string
// }

// func changeName(person *Person) {
// 	person = &Person{
// 		Name: "Olga",
// 	}
// }

// func main() {
// 	person := &Person{
// 		Name: "Eugene",
// 	}
// 	fmt.Println(person.Name)
// 	changeName(person)
// 	fmt.Println(person.Name)
// }

/////////////////////////////////////////////////////////

package main

import "fmt"

type Person struct {
	Name string
}

func changeName(person *Person) {
	person.Name = "Olga"
}

func main() {
	person := &Person{
		Name: "Eugene",
	}
	fmt.Println(person.Name)
	person = changeName(person)
	fmt.Println(person.Name)
}
