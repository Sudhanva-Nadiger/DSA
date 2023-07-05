/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head) {
            return head;
        }
        
        if(head->child) {
            Node* f = flatten(head->child);
            head->child = NULL;
            
            Node* tail = f;
            while(tail->next) {
                tail = tail->next;
            }
            
            tail->next = head->next;
            f->prev = head;
            
            Node* n = head->next;
            
            head->next = f;
            
            if(n) {
                n->prev = tail;
            }
        }
        
        head->next = flatten(head->next);
        
        return head;
    }
};