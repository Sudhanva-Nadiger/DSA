class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        
        long long int ans = 0ll;
        long long int sum = 0ll;
        
        for(int i = 0; i < k; i++) {
            mp[nums[i]] ++;
            sum += nums[i];
        }
        
        if(mp.size() == k) {
            ans = max(ans, sum);
        }
        
        for(int i = k;i < nums.size(); i++) {
            sum -= nums[i-k];
            mp[nums[i-k]]--;
            
            if(mp[nums[i-k]] == 0) {
                mp.erase(nums[i-k]);
            }
            
            sum += nums[i];
            mp[nums[i]]++;
            
            if(mp.size() == k) {
                ans = max(ans, sum);
            }
        }
        
        return ans;
    }
};