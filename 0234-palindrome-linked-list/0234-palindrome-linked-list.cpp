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
    bool isPalindrome(ListNode* head) {
        vector<int> arr;
        while(head){
            arr.push_back(head->val);
            head = head->next;
        }
        vector<int> t=arr;
        reverse(t.begin(),t.end());
        
        return t==arr;
    }
};