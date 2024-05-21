package stack

import "errors"
type Stack struct {
	items []interface{}
}

func New() *Stack {
	return &Stack{}
}

func NewStack() *Stack {
	return &Stack{}
}

func (s *Stack) Back() (interface{}, error) {
	return s.Peek()
}

func (s *Stack) Clear() {
	s.items = []interface{}{}
}

func (s *Stack) IsEmpty() bool {
	return len(s.items) == 0
}

func (s *Stack) Len() int {
	return len(s.items)
}

func (s *Stack) Peek() (interface{}, error) {
	if len(s.items) == 0 {
		return nil, errors.New("stack is empty")
	}
	return s.items[len(s.items)-1], nil
}

func (s *Stack) Pop() (interface{}, error) {
	if len(s.items) == 0 {
		return nil, errors.New("stack is empty")
	}
	item := s.items[len(s.items)-1]
	s.items = s.items[:len(s.items)-1]
	return item, nil
}

func (s *Stack) Push(item interface{}) {
	s.items = append(s.items, item)
}

func (s *Stack) Size() int {
	return s.Len()
}