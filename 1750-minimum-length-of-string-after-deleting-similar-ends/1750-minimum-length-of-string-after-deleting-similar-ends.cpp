class Solution {
public:
    int minimumLength(string s) {
        int i = 0, j = s.size()-1;
        
        while(i < j) {
            if(s[i] != s[j]) break;
            else {
                char ch = s[i];
                
               while(i < j && s[i] == ch) {
                   i++;
               }
                
                if(i == j) {
                    return 0;
                }
               
                while(j > i && s[j] == ch) {
                    j--;
                }
            }
        }
        
        if(i == j) return 1;
        
        return max(0, j-i+1);
    }
};