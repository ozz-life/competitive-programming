let p = [1,2,3], q = [1,2,3]

var isSameTree = function (p, q) {
    return JSON.stringify(p) === JSON.stringify(q)
};

////////////////////////////////////////////////////////////////////////////////

/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {boolean}
 */
var isSameTree = function(p, q) {
    if ((p == null) && (q == null)) return true;
    if ((p == null) || (q == null)) return false;
    if (p.val != q.val) return false;
    return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
};

console.log(isSameTree(p, q));