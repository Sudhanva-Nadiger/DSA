class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int j = 0;
        int count = 0;
        int ans = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) count++;
            
            while(count > 1) {
                if(nums[j] == 0) {
                    count--;
                }
                
                j++;
            }
            
            ans = max(ans, i-j);
        }
        
        return ans;
    }
};