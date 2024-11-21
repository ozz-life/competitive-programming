package main

import (
	"encoding/json"
	"fmt"
)

type Data struct {
	X int    `json:"x"`
	y string `json:"y"` 
}

func testData() {
	in := Data{1, "two"}
	fmt.Printf("%#v\n", in) // ?

	encoded, _ := json.Marshal(in)
	fmt.Println(string(encoded)) // ?

	var out Data
	json.Unmarshal(encoded, &out)
	fmt.Printf("%#v\n", out) // ?
}

func main() {
	testData()
}

/////////////////////////////////////////////////

package main

import (
	"encoding/json"
	"fmt"
)

type Data struct {
	X int    `json:"x"`
	y string `json:"y"` // ПРИВАТНОЕ ПОЛЕ!!!!!!!!!!!!!!!!!!!!!!
}

func testData() {
	in := Data{1, "two"}
	fmt.Printf("%#v\n", in) // ?

	encoded, _ := json.Marshal(in)
	fmt.Println(string(encoded)) // ПРИВАТНОЕ ПОЛЕ НЕ ИДЁТ В JSON

	var out Data
	json.Unmarshal(encoded, &out)
	fmt.Printf("%#v\n", out) // Если печатаем структуру со ВСЕМИ полями, то даже приватное поле будет напечатано. Но так как y в JSON нет, будет пустая строка
}

func main() {
	testData()
}