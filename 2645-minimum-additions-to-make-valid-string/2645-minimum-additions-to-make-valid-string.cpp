class Solution {
public:
    int addMinimum(string word) {
        int i = 0;
        int letter = 1;
        int ans = 0;
        
        for(int i = 0; i < word.size();) {
            if(letter == 1) {
                if(word[i] != 'a') {
                    ans++;
                }else{
                    i++;
                }
                
                letter = 2;
            }else if(letter == 2) {
                if(word[i] !='b') {
                    ans++;
                }else{
                    i++;
                }
                
                letter = 3;
            }else{
                if(word[i] != 'c') {
                    ans++;
                }else{
                    i++;
                }
                
                letter = 1;
            }
            
        }
        
        
        if(letter != 1) {
            ans += 3-letter+1;
        }
        
        return ans;
    }
};