/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func swap(a *ListNode, b *ListNode) {
    if b == nil {
        return
    }
    
    t := a.Val
    a.Val = b.Val
    b.Val = t
}

func swapPairs(head *ListNode) *ListNode {
    if head == nil || head.Next == nil {
        return head
    }
    var ptr *ListNode
    ptr = head
    
    for ptr != nil && ptr.Next != nil {
        swap(ptr, ptr.Next)
        ptr = ptr.Next.Next
    }
    
    return head
}