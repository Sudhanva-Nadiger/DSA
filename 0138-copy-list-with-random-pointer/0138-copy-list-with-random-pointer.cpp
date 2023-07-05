/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* ans = new Node(-1);
        Node* ptr = ans;
        unordered_map<Node*, Node*> mp;
        Node* t = head;
        while(t) {
            ptr->next= new Node(t->val);
            ptr = ptr->next;
            
            mp[t] = ptr;
            t = t->next;
        }
        
        ptr = ans->next;
        
        while(ptr) {
            ptr->random = mp[head->random];
            head = head->next;
            ptr = ptr->next;
        }
        
        return ans->next;
    }
};