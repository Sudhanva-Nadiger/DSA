class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        int i = 0;
        
        while(i < nums.size()) {
            if(nums[i] ==  i+1) {
                i++;
            }else {
                int id = nums[i]-1;
                if(nums[id] == id+1){
                    i++;
                    continue;
                }
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != i+1) {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};