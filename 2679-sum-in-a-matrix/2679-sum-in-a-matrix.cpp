class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        
        for(int i = 0; i < nums.size(); i++) {
            sort(nums[i].begin(), nums[i].end());
        }
        
        int j = nums[0].size()-1;
        int ans = 0;
        
        for(int k = 0; k < nums[0].size(); k++) {
            int maxi = 0;
            
            for(int i = 0; i < nums.size(); i++) {
                maxi = max(maxi, nums[i][j]);
            }
            
            ans += maxi;
            j--;
        }
        
        return ans;
    }
};