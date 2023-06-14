class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n = nums.size();
        vector<int> count(n);
        
        for(auto it: requests) {
            count[it[0]]++;
            
            if(it[1]+1 < n) {
                count[it[1]+1]--;
            }
        }
        
        partial_sum(begin(count), end(count), begin(count));
        sort(begin(count), end(count));
        sort(begin(nums), end(nums));
        
        int mod = 1e9+7;
        long long ans = 0ll;
        for(int i = 0; i < n; i++) {
            ans = (ans + ((long long)(count[i])*(long long)(nums[i]))%mod)%mod;
        }
        return ans;
    }
};