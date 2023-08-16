class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& nums, int time) {
        int n = nums.size();
        vector<int> left(n);
        
        for(int i = 1; i < n; i++) {
            if(nums[i] <= nums[i-1]) {
                left[i] = 1 + left[i-1];
            }
        }
        
        vector<int> right(n);
        
        for(int i = n-2; i >= 0; i--) {
            if(nums[i] <= nums[i+1]) {
                right[i] = 1 + right[i+1];
            }
        }
        
        vector<int> ans;
        
        for(int i = 0; i < n; i++) {
            if(left[i] >= time && right[i] >= time) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};