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
    ListNode* reverseList(ListNode* l,ListNode* r){
        if(l == r){
            return l;
        }
        
        ListNode* newHead = reverseList(l->next,r);
        
        l->next->next = l;
        l->next = NULL;
        return newHead;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head or !head->next){
            return head;
        }
        if(left == right){
            return head;
        }
        ListNode* temp = head;
        ListNode* l=NULL ,*leftPrev = NULL,* r=NULL,* rightNext = NULL;
    
        int count = 1;
        
        while(temp){
            if(count == left){
                l = temp;
            }
            else if(count == right){
                r = temp;
                rightNext = temp->next;
            }
            if(l and r){
                break;
            }
            if(!l)
                 leftPrev = temp;
            count++;
            temp = temp->next;
        }
        
        ListNode* n = reverseList(l,r);
        if(left!=1)
            leftPrev->next = n;
        l->next = rightNext;
        if(left == 1){
            head = n;
        }
        return head;
        
    }
};