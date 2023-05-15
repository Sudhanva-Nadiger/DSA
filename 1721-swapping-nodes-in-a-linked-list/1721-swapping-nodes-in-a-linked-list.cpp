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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *front = NULL, *temp = head;
        
        while(k) {
            if(k == 1) {
                front = temp;
            }
            
            temp = temp -> next;
            
            k--;
        }
        
        ListNode* walk = head;
        
        while(temp) {
            walk = walk->next;
            temp = temp->next;
        }
        
        
        int t = walk->val;
        walk->val = front->val;
        front->val = t;
        
        return head;
    }
};