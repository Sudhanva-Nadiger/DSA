class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp2;
        
        for(auto it : t) {
            mp2[it]++;
        }
        
        int start = -1;
        int end = -1;
        
        int c = 0;
        int count = t.size();
        unordered_map<char, int> mp1;
        int j = 0;
        for(int i = 0; i <s.size(); i++) {
            mp1[s[i]]++;
            
            if(mp1[s[i]] <= mp2[s[i]]) {
                c++;
            }
            
            
            while((j <= i) && (c == count)) {
                if(start == -1 || i-j+1 < end-start+1) {
                    end = i;
                    start = j;
                }
                
                mp1[s[j]]--;
                
                if(mp1[s[j]] < mp2[s[j]]) {
                    c--;
                }
                
                j++;
            }
        }
        
        if(start == -1) return "";
        return s.substr(start, end-start+1);
    }
};