class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int j = 0;
        int ans = 0;
        long long sum = 0;
        sort(begin(nums), end(nums));
        
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            
            while((long long)nums[i]*(i-j+1) - sum > k) {
                sum -= nums[j];
                j++;
            }
            
            ans = max(ans, i-j+1);
        }
        return ans;
    }
};