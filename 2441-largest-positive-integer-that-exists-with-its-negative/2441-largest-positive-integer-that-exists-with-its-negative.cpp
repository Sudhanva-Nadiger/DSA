class Solution {
public:
    int findMaxK(vector<int>& nums) {
        set<int> mp;
        
        for(auto it : nums) {
            if(it < 0) mp.insert(it);
        }
        
        int ans = -1;
        for(auto it : nums) {
            if(it > 0 && mp.count(-1*it)) {
                ans = max(ans, it);
            }
        }
        
        return ans;
    }
};