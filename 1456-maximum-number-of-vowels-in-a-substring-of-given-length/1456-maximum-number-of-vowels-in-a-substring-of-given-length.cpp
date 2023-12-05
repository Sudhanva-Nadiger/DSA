class Solution {
public:
    bool isVowel(char c) {
        return (
                c == 'a' || 
                c == 'e' || 
                c == 'i' || 
                c == 'o' || 
                c == 'u'
               );
    }
        
    int maxVowels(string s, int k) {
        int ans = 0;
        
        int count = 0;
        for(int i = 0; i < k; i++) {
            count += (isVowel(s[i]));
        }
        
        ans = count;
        
        for(int i = k; i < s.size(); i++) {
            count += (isVowel(s[i]) - isVowel(s[i-k]));
            ans = max(ans, count);
        }
        
        return ans;
    }
};