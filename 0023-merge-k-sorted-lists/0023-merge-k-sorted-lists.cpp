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
    struct cmp{
      bool operator()(ListNode* a, ListNode* b) {
          return a->val > b->val;
      }  
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        
        ListNode* ans = new ListNode(-1);
        auto *ptr = ans;
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        
        for(auto it : lists) {
            if(it)
                pq.push(it);
        }
        
        while(pq.size()) {
            auto *node = pq.top();
            pq.pop();
            
            ptr->next = node;
            ptr = node;
            node = node->next;
            if(node) {
                pq.push(node);
            }
        }
        
        return ans->next;
    }
};