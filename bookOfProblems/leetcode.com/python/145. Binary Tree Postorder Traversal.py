# стек:
# Сначала корень. Потом правое, прежде чем посетим левое
# Мы так делаем, потому что знаем, что будем делать с конца стека
# Мы знаем, что правое мы вытащим из стека раньше, нежели корень.
# Потом мы хотим добавить левое, потому что оно выйдет из стека раньше, чем новое правое и новое левое.

# Мы хотим добавить к результату число, только во второй раз. Потому что хотим пройти дальше.

class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        stack = [root]
        visit = [False]
        res = []
        
        while stack:
            cur, v = stack.pop(), visit.pop()
            if cur:
                if v:
                    res.append(cur.val)                
                else:
                    stack.append(cur)
                    visit.append(True)
                    stack.append(cur.right)
                    visit.append(False)
                    stack.append(cur.left)
                    visit.append(False)