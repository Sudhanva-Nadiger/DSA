class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n), right(n);
        
        int l = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 1) {
                l++;
            }else {
                left[i] = l;
                l = 0;
            }
        }
        
        if(l == n) return l-1;
        
        int r = 0;
        for(int i = n-1; i >= 0; i--) {
            if(nums[i] == 1) {
                r++;
            }else {
                right[i] = r;
                r = 0;
            }
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                ans = max(ans, left[i]+right[i]);
            }
        }
        return ans;
    }
};