class Solution {
public:
    int dp[15][(int)(1<<15)];
    int f(vector<int>& nums1, vector<int>& nums2, int ind, int mask) {
        if(ind >= nums1.size()) return 0;
        
        if(dp[ind][mask] != -1) return dp[ind][mask];
        
        int ans = INT_MAX;
        for(int i = 0; i < nums2.size(); i++) {
            if(!(mask&(1<<i))) {
                int t = (nums1[ind] ^ nums2[i]) + f(nums1, nums2, ind+1, (mask | (1 << i)));
                ans = min(ans, t);
            }
        }
        
        return dp[ind][mask] = ans;
    }
    
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        memset(dp, -1, sizeof dp);
        return f(nums1, nums2, 0, 0);
    }
};