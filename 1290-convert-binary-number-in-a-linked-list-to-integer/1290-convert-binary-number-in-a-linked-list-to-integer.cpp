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
    int ans = 0;
    int i = 0;
    void f(ListNode* head) {
        if(!head) return;
        
        f(head->next);
        
        ans += (1<<i)*head->val;
        i++;
    }
    int getDecimalValue(ListNode* head) {
        f(head);
        return ans;
    }
};