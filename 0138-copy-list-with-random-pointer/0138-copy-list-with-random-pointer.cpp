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
        unordered_map<Node*, Node*> mp;
        
        Node* ptr = head;
        Node* ans = new Node(-1);
        Node* temp = ans;
        
        while(ptr) {
            temp->next = new Node(ptr->val);
            temp = temp->next;
            
            mp[ptr] = temp;
            ptr = ptr->next;
        }
        
        temp = ans->next;
        ptr = head;
        while(ptr) {
            temp->random = mp[ptr->random];
            temp = temp->next;
            ptr =ptr->next;
        }
        
        return ans->next;
    }
};