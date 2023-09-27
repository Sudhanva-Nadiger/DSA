/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isSameTree(p *TreeNode, q *TreeNode) bool {
    if q == nil && p == nil {
        return true
    }
    
    if q == nil || p == nil || p.Val != q.Val {
        return false;
    }
    
    return isSameTree(p.Left, q.Left) && isSameTree(p.Right, q.Right)

}