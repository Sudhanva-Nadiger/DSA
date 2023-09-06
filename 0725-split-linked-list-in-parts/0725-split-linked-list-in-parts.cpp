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
    int size(ListNode* head){
        int count=0;
        while(head){
            count++;
            head=head->next;
        }
        return count;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        int n = size(head);
        if(k>=n){
            while(head and k--){
                ListNode* temp = head;
                head= head->next;
                temp->next = NULL;
                ans.push_back(temp);
            }
            if(k){
                while(k--){
                    ans.push_back(NULL);
                }
            }
            
            return ans;
        }
        else{
            if(k==1){
                ans.push_back(head);
                return ans;
            }
            
            int split = n/k;
            int sizeMorethanone = n%k;
            
                while(sizeMorethanone--){
                    ListNode* temp = head;
                    int x = split;
                    while(x-- and head){
                        head=head->next;
                    }
                    ListNode* end = head;
                    if(head)
                    head = head->next;
                    if(end)
                    end->next = NULL;
                    ans.push_back(temp);
                    if(!head){
                        break;
                    }
                }
            int sudhi = n-sizeMorethanone;
            
            while(sudhi--){
                ListNode* temp = head;
                    int x = split-1;
                    while(x-- and head){
                        head=head->next;
                    }
                    ListNode* end = head;
                    if(head)
                    head = head->next;
                    if(end)
                    end->next = NULL;
                    ans.push_back(temp);
                    if(!head){
                        break;
                    }
            }  
            
        }
        
        return ans; 
    }
};