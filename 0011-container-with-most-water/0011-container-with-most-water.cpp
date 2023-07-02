class Solution {
public:
    int maxArea(vector<int>& nums) {
        int ans = 0;
        int i = 0,j = nums.size()-1;
        
        while(i < j) {
            ans = max(ans, (j-i)*min(nums[i], nums[j]));
            if(nums[i] <= nums[j]) {
                i++;
            }else {
                j--;
            }
        }
        return ans;
    }
};