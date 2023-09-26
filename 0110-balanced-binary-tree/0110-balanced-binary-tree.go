/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

import ("math")

func f(root *TreeNode) (float64, bool) {
    if root == nil {
        return 0, true
    }
    
    lh, ok := f(root.Left)
    if !ok {
        return 0, false
    }
    
    rh, ok := f(root.Right)
    if !ok || (math.Abs(lh-rh) > 1) {
        return 0, false;
    }
    
    return math.Max(lh, rh)+1, true
}

func isBalanced(root *TreeNode) bool {
    _, res := f(root)
    return res
}