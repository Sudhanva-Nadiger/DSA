class Solution {
public:
    int maxPoints(vector<vector<int>>& nums) {
        if(nums.size() <= 2) return nums.size();
        int ans = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            unordered_map<double, int> mp;
            for(int j = 0;j < nums.size(); j++) {
                if(i != j) {
                    auto d = (double)(nums[j][0]-nums[i][0]);
                    if(d == 0) {
                        mp[1e9]++;
                    }
                    double slope = (double)(nums[j][1]-nums[i][1])/(double)(nums[j][0]-nums[i][0]);
                    mp[slope]++;
                }
            }
            
            for(auto it : mp) {
                ans = max(ans, it.second+1);
            }
        }
        
        return ans;
    }
};