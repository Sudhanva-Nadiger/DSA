class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), req = t.size();
        vector<int> mp1(150, 0), mp2(150, 0);
        
        for(auto it : t) mp1[it-'A']++;
        
        int count = 0, j = 0, start = -1, end = n;
        
        for(int i = 0; i < n; i++) {
            if(mp1[s[i]-'A'] && mp2[s[i]-'A'] < mp1[s[i]-'A']) {
                count++;
            }
            
            if(mp1[s[i]-'A'])
                mp2[s[i]-'A']++;
            
            while(j <= i && count == req) {
                if(mp1[s[j]-'A'] && mp2[s[j]-'A'] <= mp1[s[j]-'A']) {
                    count--;
                }
                
                if(mp1[s[j]-'A'])
                    mp2[s[j]-'A']--;
                
                if(i-j+1 < end-start+1) {
                    start = j;
                    end = i;
                }
                
                j++;
            }
        }
        
        if(start == -1) return "";
        
        return s.substr(start, end-start+1);
    }
};