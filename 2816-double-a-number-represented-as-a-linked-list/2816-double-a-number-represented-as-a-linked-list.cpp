/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rev(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode* n = rev(head->next);
        head->next->next = head;
        head->next = NULL;
        
        return n;
    }
    ListNode* doubleIt(ListNode* head) {
        if(!head->next && head->val == 0) return head;
        ListNode* r = rev(head);
        
        int carry = 0;
        
        ListNode* p = r;
        ListNode* tail = NULL;
        
        while(p) {
            int num = p->val;
            int mul = num*2 + carry;
            
            if(mul < 10) {
                carry = 0;
                p->val = mul;
            }else {
                carry = 1;
                p->val = mul%10;
            }
            
            if(!p->next) tail = p;
            p = p->next;
        }
        
        if(carry) tail->next = new ListNode(carry);
        
        return rev(r);
    }
};