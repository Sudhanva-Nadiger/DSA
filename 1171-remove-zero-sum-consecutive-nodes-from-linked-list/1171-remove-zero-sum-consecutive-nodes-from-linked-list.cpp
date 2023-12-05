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
    ListNode* removeZeroSumSublists(ListNode* head) {
        if(!head) return head;
        
        unordered_map<int, ListNode*> mp;
        ListNode* ans = new ListNode(0), *ptr = head, *temp = ans;
        mp[0] = ans;
        
        int cs = 0;
        while(ptr) {
            cs += ptr->val;
            
            if(mp.find(cs) == mp.end()) {
                mp[cs] = ptr;
                temp->next = ptr;
                temp = temp->next;
            } else {
                temp = mp[cs];
                ListNode* t = temp->next;
                int count = cs;
                while(t && t != ptr) {
                    count += t->val;
                    mp.erase(count);
                    t = t->next;
                }
            }
            
            ptr = ptr->next;
            temp->next = NULL;
        }
        
        return ans->next;
    }
};