class Solution {
public:
    int countMatrices(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        int sum = 0, count = 0;
        mp[0] = 1;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            count += mp[sum-target];
            mp[sum]++;
        }
        
        return count;
    }
    
    int numSubmatrixSumTarget(vector<vector<int>>& mat, int target) {
        int ans = 0,m = mat.size(), n = mat[0].size();
        
        for(int left = 0; left < n; left++) {
            vector<int> nums(m);
            
            for(int right = left;right <n; right++) {
                
                for(int row = 0; row < m; row++) {
                    nums[row] += mat[row][right];
                }
                
                ans += countMatrices(nums, target);
            }
        }
        
        return ans;
    }
};