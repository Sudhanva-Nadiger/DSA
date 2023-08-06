class Solution {
public:
    int numSplits(string s) {
        unordered_map<int, int> mp1, mp2;
        int n = s.size();
        
        if(n == 1) return 0;
        
        int ans = 0;
        
        for(int i = 1; i < n; i++) {
            mp2[s[i]-'a']++;
        }
        
        mp1[s[0]-'a']++;
        
        if(mp1.size() == mp2.size()) ans ++;
        
        for(int i = 1; i <n; i++) {
            mp1[s[i]-'a']++;
            mp2[s[i]-'a']--;
            
            if(mp2[s[i]-'a']==0) {
                mp2.erase(s[i]-'a');
            }
            
            ans += (mp1.size() == mp2.size());
        }
        return ans;
    }
};