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
    bool f(ListNode* head, int k) {
        int count=0;
        int t = k;
        while(head && k) {
            count++;
            head = head->next;
            k--;
        }
        
        return count == t;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) {
            return NULL;
        }
        
        if(f(head, k)) {
            ListNode* prev = NULL, *next = head;
            ListNode* h = head;
            for(int i = 0; i < k; i++) {
                next = head->next;
                head->next = prev;
                prev = head;
                
                head = next;                
            }
            
            ListNode* newNode = reverseKGroup(next, k);
            h->next = newNode;
            
            return prev;
        }
        
        return head;
    }
};