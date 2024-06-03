class Solution {
public:
    int appendCharacters(string s, string t) {
        int n = t.size(), j = 0;
        
        for(int i = 0; i < s.size() && j < n; i++) {
            j += s[i] == t[j];
        }
        
        return n-j;
    }
};