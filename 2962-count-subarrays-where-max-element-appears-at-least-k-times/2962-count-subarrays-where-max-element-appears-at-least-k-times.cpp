class Solution {
public:
    #define ll long long
    
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), maxi = *max_element(nums.begin(), nums.end());
        
        ll ans = 0, j = 0, count = 0;
        for(int i = 0; i < n; i++) {
            count += nums[i] == maxi;
            while(count >= k) {
                count -= (nums[j] == maxi);
                j++;
            }
            
            ans += j;
        }
        
        return ans;
    }
};