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
    int carry;
public:
    int getLength(ListNode* head){
        int count = 0;
        while(head){
            count++;
            head = head->next;
        }
        
        return count;
    }
    
    ListNode* add(ListNode* l1,ListNode* l2){
        if(!l1){
            return NULL;
        }
        int n = l1->val+l2->val;
        ListNode* ans = new ListNode(n);
        ans->next = add(l1->next,l2->next);
        
        if(carry == 1){
            ans->val += 1;
        }
        
        if(ans->val<=9){
            carry = 0;
        }
        
        else{
            carry = 1;
            ans->val = ans->val%10;
        }

        return ans;
        
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int s1 = getLength(l1);
        int s2 = getLength(l2);
        if(s2>s1){
            return addTwoNumbers(l2,l1);
        }
        int diff = abs(s1-s2);
        
        ListNode* dummy = new ListNode(-1);
        ListNode* walk = dummy;
        while(diff--){
            ListNode* n = new ListNode(0);
            walk->next = n;
            walk = walk->next;
        }
        walk->next = l2;
        dummy = dummy->next;
        carry = 0;
        ListNode* ans =  add(l1,dummy);
        if(carry == 1){
            dummy = new ListNode(1);
            dummy->next = ans;
            ans = dummy;
        }
        
        return ans;
    }
};