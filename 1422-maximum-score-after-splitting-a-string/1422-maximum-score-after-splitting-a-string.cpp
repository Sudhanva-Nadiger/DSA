class Solution {
public:
    int maxScore(string s) {
        int totOnes = 0, ans = 0, zeros = 0, ones = 0;
        for(char c: s) {
            totOnes += (c == '1');
        }
        
        s.pop_back();
        for(char c: s) {
            zeros += (c == '0');
            ones += (c == '1');
            
            ans = max(ans, zeros + (totOnes - ones));
        }
        
        return ans;
    }
};