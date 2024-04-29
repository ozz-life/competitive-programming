package stack

import "fmt"

type Stack struct {
	items []string
}

func New() *Stack {
	return &Stack{}
}

func (s *Stack) Push(item string) {
	s.items = append(s.items, item)
	fmt.Println("ok")
}

func (s *Stack) Peek() {
	if len(s.items) == 0 {
		fmt.Println("error")
	} else {
		fmt.Println(s.items[len(s.items)-1])
	}
}

func (s *Stack) Back() {
	s.Peek()
}

func (s *Stack) Pop() {
	if len(s.items) == 0 {
		fmt.Println("error")
	} else {
		item := s.items[len(s.items)-1]
		s.items = s.items[:len(s.items)-1]
		fmt.Println(item)
	}
}

func (s *Stack) Size() {
	fmt.Println(len(s.items))
}

func (s *Stack) Clear() {
	s.items = []string{}
	fmt.Println("ok")
}

func (s *Stack) IsEmpty() bool {
	return len(s.items) == 0
}