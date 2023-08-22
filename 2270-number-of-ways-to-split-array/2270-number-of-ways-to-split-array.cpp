class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum = accumulate(begin(nums), end(nums), 0ll);
        long long ans = 0;
        
        long long cs = 0ll;
        for(int i = 0; i < nums.size()-1; i++) {
            cs += nums[i];
            
            ans += (cs >= (sum - cs));
        }
        
        return ans;
    }
};