class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        
        while(i < n) {
            if(i == nums[i]-1 || nums[i] == nums[nums[i]-1]) {
                i++;
            }else {
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(nums[i] != i+1) {
                ans.push_back(nums[i]);
            }
        }
        
        return ans;
    }
};