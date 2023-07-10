class Solution {
public:
    int dp[1000][1000];
    int ans = 0;
    
    int f(vector<int>& nums1, vector<int>& nums2, int i, int j) {
        if(i >= nums1.size() || j >= nums2.size()) {
            return 0;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int t = 0;
        if(nums1[i] == nums2[j]) {
            t = 1+f(nums1, nums2, i+1, j+1);
            ans = max(ans, t);
        }
        
        f(nums1, nums2, i+1, j);
        f(nums1, nums2, i, j+1);
        
        return  dp[i][j] = t;;
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        memset(dp, -1, sizeof dp);
        f(nums1, nums2, 0, 0);
        return ans;
    }
};