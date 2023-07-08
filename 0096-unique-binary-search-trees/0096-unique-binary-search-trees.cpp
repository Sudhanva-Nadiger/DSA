class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1);
        dp[0] =  1;
        dp[1] = 1;
        
        
        for(int i = 2; i <= n; i++) {
            int left = 0, right = i-1;
            int count = 0;
            while(left < i) {
                count += (dp[left]*dp[right]);
                left++;
                right--;
            }
            
            dp[i] = count;
        }
        
        return dp[n];
    }
};