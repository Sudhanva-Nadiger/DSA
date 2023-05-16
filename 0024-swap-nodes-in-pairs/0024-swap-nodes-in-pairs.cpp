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
    ListNode* swapPairs(ListNode* head) {
        if(!head) {
            return head;
        }
        ListNode* curr = head;
        ListNode* next = head->next;
        
        while(next && curr) {
            int t = curr->val;
            curr->val = next->val;
            next->val = t;
            
            curr = next->next;
            if(curr)
                next = curr->next;
        }
        
        return head;
    }
};