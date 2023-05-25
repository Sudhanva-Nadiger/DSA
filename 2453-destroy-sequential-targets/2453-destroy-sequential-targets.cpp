class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        unordered_map<int, int> mp;
        
        for(int i = 0;i < nums.size(); i++) {
            int r = (nums[i] + space)%space;
            
            mp[r]++;
        }
        
        int ans = INT_MAX;
        int count = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            int r = (nums[i] + space)%space;
            
            if(mp[r] > count) {
                count = mp[r];
                ans = nums[i];
            }else if(mp[r] == count) {
                ans = min(ans, nums[i]);
            }
        }
        
        return ans;
    }
};