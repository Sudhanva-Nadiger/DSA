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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-101);
        auto *ptr = dummy;
        
        auto *next = head;
        
        while(next) {
            if(next->val != ptr->val) {
                ptr->next = next;
                ptr = ptr->next;
                next = next->next;
                
                ptr->next = NULL;
            }else {
                next = next->next;
            }
        }
    
        return dummy->next;
    }
};