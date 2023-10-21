class Solution {
public:
    int numberOfSubstrings(string s) {

        int j = 0, n = s.size(), ans = 0;
        unordered_map<char, int> mp;
        
        for(int i = 0; i < n; i++) {
            mp[s[i]]++;
            
            while(mp.size() == 3) {
                ans += (n-i);
                
                mp[s[j]]--;
                if(mp[s[j]] == 0) {
                    mp.erase(s[j]);
                }
                
                j++;
            }
        }
        
        return ans;
    }
};