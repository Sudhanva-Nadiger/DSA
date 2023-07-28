class Solution {
public:
    int maxLen(vector<bool>& dp) {
        int n = dp.size();
        int ans = 0;
        int prev = -1;
        
        for(int i = 0; i < n; i++) {
            if(!dp[i]) {
                ans = max(ans, i-prev);
                prev =  i;
            }
            
            dp[i] = false;
        }
        
        return ans;
    }
    
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        vector<bool> dp(n, false);
        
        for(int i = 0; i < n-1; i++) {
            if(i%2 == 0) {
                dp[i] = (arr[i] < arr[i+1]);
            }else {
                dp[i] = (arr[i] > arr[i+1]);
            }
        }
        
        int ans = maxLen(dp);
        
        for(int i = 0; i < n-1; i++) {
            if(i%2 == 0) {
                dp[i] = (arr[i] > arr[i+1]);
            }else {
                dp[i] = (arr[i] < arr[i+1]);
            }
        }
        
        ans = max(ans, maxLen(dp));
        
        return ans;
    }
};