class Solution {
public:
    int totalMoney(int n) {
        int prev = 0, ans = 0;
        
        int cs = 0;
        for(int i = 0; i < n; i++) {
            if(i%7 == 0) {
                cs = prev+1;
                
                prev = cs;
            } else {
                cs += 1;
            }
            
            ans += cs;
        }
        
        return ans;
    }
};