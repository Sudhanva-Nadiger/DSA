class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int, int>> st;
        st.insert({0, 0});
        
        unordered_map<char, pair<int, int>> mp;
        
        mp['E'] = {1, 0};
        mp['W'] = {-1, 0};
        mp['N'] = {0, 1};
        mp['S'] = {0, -1};
        
        
        pair<int, int> curr = {0, 0};
        for(auto it : path) {
            curr.first += mp[it].first;
            curr.second += mp[it].second;
            
            if(st.count(curr)) return true;
            
            st.insert(curr);
        }
        
        return false;
    }
};