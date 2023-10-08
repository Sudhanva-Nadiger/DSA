class Solution {
public:
    vector<vector<vector<int>>> dp;
    int f(vector<int>& nums1, vector<int>& nums2, int i, int j, bool taken = false) {
        if(i >= nums1.size() || j >= nums2.size()) {
            return taken ? 0 : -1e9;
        }
        
        if(dp[i][j][taken] != INT_MIN) {
            return dp[i][j][taken];
        }
        
        int a = nums1[i]*nums2[j] + f(nums1, nums2, i+1, j+1, true);
        int b = f(nums1, nums2, i+1, j, taken | false);
        int c = f(nums1, nums2, i, j+1, taken | false);
        
        return dp[i][j][taken] = max({a, b, c});
    }
    
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        dp = vector<vector<vector<int>>>(nums1.size(), vector<vector<int>>(nums2.size(), vector<int>(3, INT_MIN)));
        return f(nums1, nums2, 0, 0);
    }
};