class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        int maxi = nums[n-1];
        int ans = 0;
        for(int i = n-1; i>= 0; i--) {
            ans = max(ans, maxi-nums[i]);
            maxi = max(nums[i], maxi);
        }
        return ans;
    }
};