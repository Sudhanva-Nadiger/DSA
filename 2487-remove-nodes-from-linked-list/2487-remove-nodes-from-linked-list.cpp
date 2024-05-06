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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st;
        
        while(head){
            while(st.size() and st.top()->val < head->val){
                st.pop();
            }
            
            st.push(head);
            head = head->next;
        }
        
        ListNode* tail = st.top();
        st.pop();
        
        if(!st.size()){
            return tail;
        }
        while(st.size()){
            ListNode* top = st.top();
            st.pop();
            
            top->next = tail;
            tail = top;
        }
        
        
        return tail;
        
    }
};