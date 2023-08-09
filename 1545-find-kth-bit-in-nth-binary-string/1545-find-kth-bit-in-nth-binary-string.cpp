class Solution {
public:
    char findKthBit(int n, int k) {
        vector<int> dp;
        dp.push_back(0);
        
        for(int i = 1; i < n; i++) {
            dp.push_back(1);
            
            int t = dp.size();
            for(int i = t-2; i >= 0; i--) {
                dp.push_back(!dp[i]);
            }
        }
        
        return dp[k-1]+'0';
    }
};