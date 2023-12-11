class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        map<int, map<int, int>> mp;
        
        for(auto log: logs) {
            auto id = log[0], t = log[1];
            mp[id][t]++;
        }
        
        vector<int> ans(k);
        for(auto it : mp) {
            ans[it.second.size()-1]++;
        }
        
        return ans;
    }
};