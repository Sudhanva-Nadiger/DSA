class Solution {
public:
    void f(vector<int>& arr, unordered_map<int, int>& mp) {
        
        for(int i = 0; i < arr.size(); i++){
            mp[arr[i]] = max(mp[arr[i]], i);
        }
    }
    
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> mp;
        
        f(A, mp);
        f(B, mp);
        
        vector<int> ans(A.size(), 0);
        
        for(int el : A) {
            int i = mp[el];
            
            while(i < ans.size()) {
                ans[i] ++;
                i++;
            }
        }
        
        return ans;
    }
};