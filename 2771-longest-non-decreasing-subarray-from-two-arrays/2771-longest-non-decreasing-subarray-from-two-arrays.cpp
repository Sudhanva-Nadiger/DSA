int f(int i,int flag,vector<int>&nums1,vector<int>&nums2,int n,vector<vector<int>>&dp)
{
    if(i == n)
    {
        return 0;
    }
    if(dp[i][flag] != -1)
        return dp[i][flag];
    if(flag == 0)
    {
        int pick1 = f(i+1,1,nums1,nums2,n,dp) + 1;
        int pick2 = f(i+1,2,nums1,nums2,n,dp) + 1;
        int notpick = f(i+1,0,nums1,nums2,n,dp);
        return dp[i][flag] = max({pick1,pick2,notpick});
    }
    else if(flag == 1)
    {
        int pick1 = 0;
        int pick2 = 0;
        if(nums1[i-1] <= nums1[i])
            pick1 = f(i+1,1,nums1,nums2,n,dp) + 1;
        if(nums1[i-1] <= nums2[i])
            pick2 = f(i+1,2,nums1,nums2,n,dp) + 1;
        return dp[i][flag] = max(pick1,pick2);
    }
    else if(flag == 2)
    {
        int pick1 = 0;
        int pick2 = 0;
        if(nums2[i-1] <= nums1[i])
            pick1 = f(i+1,1,nums1,nums2,n,dp) + 1;
        if(nums2[i-1] <= nums2[i])
            pick2 = f(i+1,2,nums1,nums2,n,dp) + 1;
        return dp[i][flag] = max(pick1,pick2);
    }
    return dp[i][flag] = 0;
}




class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int flag = 0;
        int n = nums1.size();
        vector<vector<int>>dp(n,vector<int>(3,-1));
        return f(0,flag,nums1,nums2,n,dp);
    }
};