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
    ListNode* partition(ListNode* head, int x) {
        ListNode* after = new ListNode(-1);
        ListNode* ptr = after;
        
        ListNode* before = new ListNode(-1);
        ListNode* t = before;
        
        while(head) {
            ListNode* next = head->next;
            if(head->val < x) {
                t->next = head;
                t = t->next;
                
                t->next = NULL;
            }else {
                ptr->next = head;
                ptr = ptr->next;
                
                ptr->next = NULL;
            }
            
            head = next;
        }
        
        t->next = after->next;
        
        return before->next;
    }
};