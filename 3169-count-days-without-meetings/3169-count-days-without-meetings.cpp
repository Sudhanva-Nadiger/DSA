class Solution {
public:
    int countDays(int days, vector<vector<int>>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0, n = nums.size();
        for(int i = 1; i< n; i++) {
            if(nums[i][0] > nums[i-1][1]) {
                ans += (nums[i][0] - nums[i-1][1] - 1);
            }
            
            nums[i][1] = max(nums[i][1], nums[i-1][1]);
        }
        
        ans += (nums[0][0]-1);
        
        ans += max(days - nums[n-1][1], 0);
        
        return ans;
    }
};