class Solution {
public:
    int f(string& s, int k, char ch) {
        int j = 0;
        int ans = 0;
        int count = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ch) {
                count++;
            }
            
            while(count > k) {
                if(s[j] == ch) {
                    count--;
                }
                
                j++;
            }
            
            ans = max(ans, i-j+1);
        }
        
        return ans;
    }
    
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(f(answerKey, k, 'T'),f(answerKey, k, 'F'));
    }
};