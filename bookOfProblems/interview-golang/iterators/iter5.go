package main

import (
	"fmt"
)

// Explicit struct for the state
Backward_Iterator :: struct($E: typeid) {
	slice: []E,
	idx:   int,
}

// Explicit construction for the iterator
backward_make :: proc(s: []$E) -> Backward_Iterator(E) {
	return {slice = s, idx = len(s)-1}
}

backward_iterate :: proc(it: ^Backward_Iterator($E)) -> (elem: E, idx: int, ok: bool) {
	if it.idx >= 0 {
		elem, idx, ok = it.slice[it.idx], it.idx, true
		it.idx -= 1
	}
	return
}

func main() {

}