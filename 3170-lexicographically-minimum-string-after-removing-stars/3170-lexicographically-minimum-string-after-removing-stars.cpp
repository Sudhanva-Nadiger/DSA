class Solution {
public:
    string clearStars(string s) {
        map<char,vector<int>> mp;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(s[i] == '*') {
                auto it = mp.begin();
                
                if(it != mp.end() && it->second.size()) {
                    int index = it->second.back();
                    s[index] = '*';
                    it->second.pop_back();
                    
                    if(it->second.size() == 0) {
                        mp.erase(it->first);
                    }
                }
            } else {
                mp[s[i]].push_back(i);
            }
        }
        
        string ans = "";
        
        for(auto it : s)
            if(it != '*')
                ans += it;
        return ans;
    }
};