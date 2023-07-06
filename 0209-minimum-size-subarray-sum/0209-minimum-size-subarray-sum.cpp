class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int j = 0;
        int ans = 1e9;
        
        int cs = 0;
        int i;
        
        for(i = 0; i < nums.size(); i++) {
            cs += nums[i];
            
            while(j <= i && cs >= target) {
                ans = min(ans, i-j+1);
                cs -= nums[j];
                j++;
            }
        }
        
        // while(j <= i && cs >= target) {
        //     ans = min(ans, i-j+1);
        //     cs -= nums[j];
        //     j++;
        // }
        
        return ans == 1e9 ? 0 : ans;
    }
};