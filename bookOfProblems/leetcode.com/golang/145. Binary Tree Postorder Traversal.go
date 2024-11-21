
// Рекурсивное.
func postorderTraversal(root *TreeNode) []int {
    var result []int
    if root == nil {
        return result
    }
    
    left := postorderTraversal(root.Left)
    right := postorderTraversal(root.Right)
    
    result = append(result, left...)
    result = append(result, right...)
    result = append(result, root.Val)
    
    return result
}

// Стек на слайсе
/////////////////////////////////////////////////////

func postorderTraversal(root *TreeNode) []int {
    if root == nil {
        return nil
    }

    type nodeStatus struct {
        node   *TreeNode
        visited bool
    }

    var stack []*nodeStatus
    stack = append(stack, &nodeStatus{node: root, visited: false})
    var result []int

    for len(stack) > 0 {
        top := stack[len(stack)-1]
        stack = stack[:len(stack)-1]

        if top.node != nil {
            if top.visited {
                result = append(result, top.node.Val)
            } else {
                // Push children in reverse order to simulate postorder traversal
                stack = append(stack, &nodeStatus{node: top.node, visited: true})
                stack = append(stack, &nodeStatus{node: top.node.Right, visited: false})
                stack = append(stack, &nodeStatus{node: top.node.Left, visited: false})
            }
        }
    }

    return result
}

// Наш стек
/////////////////////////////////////////////////

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

func postorderTraversal(root *TreeNode) []int {
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
				// Push children in reverse order to simulate postorder traversal
				stack.Push(&nodeStatus{node: top.node, visited: true})
				stack.Push(&nodeStatus{node: top.node.Right, visited: false})
				stack.Push(&nodeStatus{node: top.node.Left, visited: false})
			}
		}
	}

	return result
}