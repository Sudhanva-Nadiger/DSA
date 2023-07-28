class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        unordered_map<int, vector<int>> mp;
        int m = nums.size();
        int n = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < nums[i].size(); j++) {
                mp[i+j].push_back(nums[i][j]);
            }
            
            n = max(n, (int)nums[i].size());
        }
        
        vector<int> ans;
        
        for(int i = 0; i < 2*max(m, n)-1; i++) {
            for(int j = mp[i].size()-1; j >= 0; j--) {
                ans.push_back(mp[i][j]);
            } 
        }
        
        return ans;
    }
};