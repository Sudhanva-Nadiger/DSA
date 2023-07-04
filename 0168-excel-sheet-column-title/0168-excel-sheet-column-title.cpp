class Solution {
public:
    string convertToTitle(int n) {
        string ans = "";
        
        while(n) {
            int t = n%26;
            char c;
            
            if(t == 0) {
                c = 'Z';
                n = n/26-1;
            }else {
                c = 'A' + t-1;
                n /= 26;
            }
            
            ans = c + ans;
        }
        
        return ans;
    }
};