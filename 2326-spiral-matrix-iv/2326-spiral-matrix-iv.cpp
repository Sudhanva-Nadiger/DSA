
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> arr(m,vector<int>(n,-1));
        
        ListNode* t = head;
        int srow = 0;
        int scol = 0;
        int er = m-1;
        int ec = n-1;
        
        while(1){
            if(!t){
                return arr;
            }
            for(int i = scol ;i<=ec and t != NULL;i++){
             arr[srow][i] = t->val;
            t=t->next;
        }
        
        if(!t){
            return arr;
        }
        
        srow++;
        for(int i = srow;i<=er and t!=NULL;i++){
            arr[i][ec] = t->val;
            t=t->next;
        }
        if(!t){
            return arr;
        }
        ec--;
        
        for(int i = ec;i>=scol and t != NULL;i--){
            arr[er][i] = t->val;
            t=t->next;
        }
        if(!t){
            return arr;
        }
        er--;
        for(int i = er;i>=srow and t!= NULL;i--){
            arr[i][scol] = t->val;
            t=t->next;
        }
        scol++;
        if(!t){
            return arr;
        }
            
        }
        
        return arr;
        
        
    }
};