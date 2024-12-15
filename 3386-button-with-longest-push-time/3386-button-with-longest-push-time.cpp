class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        map<int, int> mp;
        mp[events[0][0]] = events[0][1];
        
        int ans = events[0][0], maxTime = events[0][1];
        
        for(int i = 1; i < events.size(); i++) {
            int key = events[i][0];
            int diff = events[i][1] - events[i-1][1];
            
            mp[key] = max(mp[key], diff);
            
            
            if(mp[key] > maxTime) {
                maxTime = mp[key];
                ans = key;
            } else if(mp[key] == maxTime) {
                ans = min(ans, key);
            }

        }
        
        return ans;
    }
};