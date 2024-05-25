class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        map<int, int> mp, colors;
        vector<int> ans;
        for(auto it: queries) {
            int ball = it[0], color = it[1];
            if(mp.find(ball) != mp.end()) {
                int prevColor = mp[ball];
                colors[prevColor]--;
                
                if(colors[prevColor] == 0) {
                    colors.erase(prevColor);
                }
            }
            
             mp[ball] = color;
             colors[color]++;
            
            ans.push_back(colors.size());
        }
        
        return ans;
    }
};