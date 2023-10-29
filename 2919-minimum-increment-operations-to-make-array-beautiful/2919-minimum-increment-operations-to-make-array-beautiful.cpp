class Solution {
public:
    #define ll long long
    vector<ll> dp;
    
    ll f(vector<ll>& nums, int i) {
        if(i > nums.size()-3) return 0;
        
        if(dp[i] != -1) return dp[i];
        
        ll ans = 1e18;
        for(int id = i; id < i + 3 && id < nums.size(); id++) {
            
            ll t = (ll)((ll)nums[id] + f(nums, id+1));
            ans = min(ans, t);
        }
        
        return dp[i] = ans;
    }
    
    long long minIncrementOperations(vector<int>& nums, int k) {
       
        vector<ll> arr(nums.size(), 0ll);
        for(int i = 0; i < nums.size(); i++) {
            arr[i] = max((ll)(k-nums[i]), 0ll);
        }
        dp = vector<ll>(nums.size()+1, -1ll);
        return f(arr, 0);
    }
};