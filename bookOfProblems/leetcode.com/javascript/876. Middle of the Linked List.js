/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var middleNode = function (head) {

    /* Solution with pointers
     * Time complexity O(n)
     * Space complexity O(1)
     **************************************************************************/

    let [fastPointer, slowPointer] = [head, head]
    while (fastPointer && fastPointer.next) {
        fastPointer = fastPointer.next.next
        slowPointer = slowPointer.next
    }
    return slowPointer

    /* Solution with array
     * Time complexity O(n)
     * Space complexity O(n)
     **************************************************************************/

    let nodes = []
    let length = 1
    while (head) {
        nodes.push(head)
        head = head.next
    }

    const middle = nodes.length % 2 === 0 ? nodes.length / 2 : Math.ceil(nodes.length / 2) - 1;

    return nodes[middle]
};