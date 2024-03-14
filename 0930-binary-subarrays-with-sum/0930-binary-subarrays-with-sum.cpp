class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int ans = 0,sum = 0;
        for(auto it : nums) {
            sum += it;
            ans += mp[sum-goal];
            mp[sum]++;
        }
        return ans;
    }
};