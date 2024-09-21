class Solution {
public:
    #define ll long long
    
    ll min = numeric_limits<ll>::min();
    
    vector<vector<ll>> dp;
    ll f(vector<int>& nums, int i, int j, vector<int>& arr) {
        
        if(i == nums.size()) {
            if(j == arr.size()) return 0;
            
            return -1e15;
        }
        
        if(j == arr.size()) return 0;
        
        if(dp[i][j] != min) return dp[i][j];
        
        ll take = (ll)nums[i]*(ll)arr[j] + f(nums, i+1, j+1, arr);
        ll notTake = f(nums, i+1, j, arr);
        
        return dp[i][j] = max(take, notTake);
    }
    
    long long maxScore(vector<int>& a, vector<int>& b) {
        dp = vector<vector<ll>>(b.size(), vector<ll>(5, min));
        return f(b, 0, 0, a);
    }
};