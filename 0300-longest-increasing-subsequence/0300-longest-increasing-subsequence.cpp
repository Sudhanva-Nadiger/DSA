class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ret;
        ret.push_back(nums[0]);
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > ret.back()) {
                ret.push_back(nums[i]);
            }else {
                int id = lower_bound(ret.begin(), ret.end(), nums[i])-ret.begin();
                ret[id] = nums[i];
            }
        }
        
        return ret.size();
    }
};