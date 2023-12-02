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
var reverseList = function (head) {

    let prev = null;
    while (head) [head.next, head, prev] = [prev, head.next, head];
    return prev;

    /* 
     * recursive
     * 
     ****************************************************************************/

    // var reverseList = (old, nev = null) =>
    //     !old ? nev : reverseList(old.next, new ListNode(old.val, nev));

    /* 
     *     https://media.geeksforgeeks.org/wp-content/cdn-uploads/RGIF2.gif
     * 
     ****************************************************************************/

    // let prev = null;
    // let current = head;
    // let next = null;

    // while (head) {
    //     next = current.next // next as synonym temp
    //     current.next = prev
    //     prev = current
    //     current = next
    // }

    // return prev

};