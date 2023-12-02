class Solution {
public:
    vector<int> getPrequencyMap(string& str) {
        vector<int> mp(26);
        for(auto it : str) {
            mp[it-'a']++;
        }
        return mp;
    }
    
    int countCharacters(vector<string>& words, string chars) {
        vector<int> mp = getPrequencyMap(chars);
        int ans = 0;
        
        for(auto it : words) {
            auto fr = getPrequencyMap(it);
            int i;
            
            for(i = 0; i < 26; i++) {
                if(fr[i] > mp[i]) {
                    break;
                }
            }
            
            if(i == 26) ans += it.size();
        }
        
        return ans;
    }
};