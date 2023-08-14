class Solution {
public:
    vector<vector<vector<int>>> dp;
    int n = 0, m = 0;
    
    int f(vector<int>& nums1, vector<int>& nums2, int i, int j, bool selected) {
        if(i == n || j == m) {
            if(selected) return 0;
            return -1e9;
        }
        
        if(dp[i][j][selected] != INT_MIN) return dp[i][j][selected];
        
        int a = f(nums1, nums2, i, j+1, selected);
        int b = f(nums1, nums2, i+1, j, selected);
        int c = nums1[i]*nums2[j] + f(nums1, nums2, i+1, j+1, true);
        
        return dp[i][j][selected] = max({a, b, c});
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size(), m = nums2.size();
        dp = vector<vector<vector<int>>>(n, vector<vector<int>>(m, vector<int>(3, INT_MIN)));
        return f(nums1, nums2, 0, 0, false);
    }
};