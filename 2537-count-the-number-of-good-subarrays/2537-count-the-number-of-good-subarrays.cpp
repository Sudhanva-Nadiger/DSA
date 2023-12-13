class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long ans = 0;
        int j = 0, n = nums.size();
        unordered_map<int, int> mp;
        
        int count = 0;
        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
            count += mp[nums[i]]-1;
            
            while(count >= k) {
                mp[nums[j]]--;
                count -= mp[nums[j]];
                
                j++;
            }
            
            ans += j;
        }
        
        return ans;
    }
};