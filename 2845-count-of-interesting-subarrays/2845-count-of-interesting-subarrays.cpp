class Solution {
public:
    #define ll long long
    long long countInterestingSubarrays(vector<int>& nums, int mod, int k) {
        ll ans = 0, n = nums.size();
        
        for(int i = 0; i < n; i++) {
            nums[i] = (nums[i]%mod == k);
        }
        
        unordered_map<ll, ll> mp;
        ll sum = 0ll;
        
        mp[0] = 1;
        
        for(int i = 0; i < n; i++) {
            sum = (sum+nums[i])%mod;
            
            ans += mp[(sum-k+mod)%mod];
            
            mp[sum]++;
        }
        
        return ans;
    }
};