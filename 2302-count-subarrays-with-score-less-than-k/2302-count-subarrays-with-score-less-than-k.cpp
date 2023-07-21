class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        
        int j = 0;
        long long sum = 0;
        long long ans = 0;
        
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            
            while(((long long)(i-j+1)*sum) >= k) {
                sum -= nums[j];
                j++;
            }
            
            ans += (i-j+1);
        }
        
        return ans;
    }
};