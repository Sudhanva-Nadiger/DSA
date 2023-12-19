class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        for(auto& it : grid)
            for(auto i : it)
                nums.push_back(i);
        
        sort(nums.begin(), nums.end());
        int target = nums[nums.size()/2], ans = 0;
        for(int it : nums) {
            int diff = abs(target-it);
            if(diff%x == 0) {
                ans += diff/x;
            } else {
                return -1;
            }
        }
        
        return ans;
    }
};