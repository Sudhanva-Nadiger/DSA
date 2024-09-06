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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> st(nums.begin(), nums.end());
        
        while(head && st.count(head->val)) {
            head = head->next;
        }
        
        ListNode* ptr = head, *prev = new ListNode(-1);
        
        while(ptr) {
            if(st.count(ptr->val)) {
                prev->next = ptr->next;
            } else {
                prev->next = ptr;
                prev = prev->next;
            }
            
            ptr = ptr->next;
        }
        
        return head;
    }
};