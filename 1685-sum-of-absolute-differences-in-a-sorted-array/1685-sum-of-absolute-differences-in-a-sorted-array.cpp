class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref = nums, suff = nums;
        
        for(int i = 1; i < n; i++) {
            pref[i] += pref[i-1];
            suff[n-i-1] += suff[n-i];
        }
        
        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++) {
            int lc = i, rc = n-i-1;
            int ls = nums[i]*lc - (i > 0 ? pref[i-1] : 0);
            int rs = (i+1 < n ? suff[i+1] - nums[i]*rc : 0);
            ans[i] = ls+rs;
        }
        return ans;
    }
};