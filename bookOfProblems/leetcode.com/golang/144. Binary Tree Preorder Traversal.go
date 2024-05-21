func preorderTraversal(root *TreeNode) []int {
    var result []int
    if root == nil {
        return result
    }
    
    left := preorderTraversal(root.Left)
    right := preorderTraversal(root.Right)
    
    result = append(result, root.Val)
    result = append(result, left...)    
    result = append(result, right...)
    
    return result
}

/////////////////////////////////////////////////////////////

type Stack struct {
	items []interface{}
}

func NewStack() *Stack {
	return &Stack{}
}

func (s *Stack) Push(item interface{}) {
	s.items = append(s.items, item)
}

func (s *Stack) Peek() interface{} {
	if len(s.items) == 0 {
		return nil
	}
	return s.items[len(s.items)-1]
}

func (s *Stack) Pop() interface{} {
	if len(s.items) == 0 {
		return nil
	}
	item := s.items[len(s.items)-1]
	s.items = s.items[:len(s.items)-1]
	return item
}

func (s *Stack) Size() int {
	return len(s.items)
}

func (s *Stack) Clear() {
	s.items = []interface{}{}
}

func (s *Stack) IsEmpty() bool {
	return len(s.items) == 0
}

func preorderTraversal(root *TreeNode) []int {
	if root == nil {
		return nil
	}

	type nodeStatus struct {
		node    *TreeNode
		visited bool
	}

	stack := NewStack()
	stack.Push(&nodeStatus{node: root, visited: false})
	var result []int

	for !stack.IsEmpty() {
		top := stack.Pop().(*nodeStatus)

		if top.node != nil {
			if top.visited {
				result = append(result, top.node.Val)
			} else {
                stack.Push(&nodeStatus{node: top.node.Right, visited: false})
				stack.Push(&nodeStatus{node: top.node.Left, visited: false})
				stack.Push(&nodeStatus{node: top.node, visited: true})
			}
		}
	}

	return result
}