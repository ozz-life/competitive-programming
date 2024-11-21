/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function getDecimalValue(head) {

    /* Solution with array
     **************************************************************************/
    // let nodes = []

    // while (head) {
    //     nodes.push(head.val)
    //     head = head.next
    // }

    // let stringNodes = nodes.join('')
    // let result = parseInt(stringNodes, 2);

    // return result;

    /* 1-line recursive solution
     **************************************************************************/

    // const getDecimalValue = (head, dec = 0) =>
    //     !head ? dec : getDecimalValue(head.next, dec * 2 + head.val);

    /* bitwise: https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/discuss/461356/JavaScript-Easy-to-understand-bit-operator
     **************************************************************************/

    let result = 0;
    while (head) {
        result = result << 1 | head.val;
        head = head.next;
    }
    return result;

}