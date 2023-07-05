/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        if(!node->next) node = NULL;
        
        auto *next = node->next;
        auto *nextNext = next->next;
        
        node->val = next->val;
        
        node->next = nextNext;
    }
};