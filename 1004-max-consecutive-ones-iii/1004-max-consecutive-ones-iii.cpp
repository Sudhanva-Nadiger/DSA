class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0;
        int j = 0;
        
        int count = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                count++;
            }
            
            while(count > k) {
                if(nums[j] == 0) {
                    count--;
                }
                
                j++;
            }
            
            ans = max(ans, i-j+1);
        }
        
        return ans;
    }
};