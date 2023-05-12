class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxTillNow(n, 0);
        
        int maxi = 0;
        
        for(int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
            maxTillNow[i] = maxi;
        }
        
        vector<long long int> ans(n, 0ll);
        
        long long int prev = 0ll;
        
        for(int i = 0; i < n; i++) {
            long long int curr = nums[i] + maxTillNow[i] + prev;
            ans[i] = curr;
            prev = curr;
        }
        
        return ans;
    }
};