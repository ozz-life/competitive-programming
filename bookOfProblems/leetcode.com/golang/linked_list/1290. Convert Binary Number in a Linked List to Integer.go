/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 func getDecimalValue(head *ListNode) int {
    s := ""

    for i := head; i != nil; i = i.Next {
        s += strconv.Itoa(i.Val)
    }

    answer, _ := strconv.ParseInt(s, 2, 32)

    return int(answer)
}