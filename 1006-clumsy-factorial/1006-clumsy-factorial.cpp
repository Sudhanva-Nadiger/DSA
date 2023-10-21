class Solution {
public:
    int calc(int n, bool flag = true) {
        int ans = n;
        if(n > 1) {
            ans = ans*(n-1);
        }
        
        if(n > 2) {
            ans = ans/(n-2);
        }
        
        if(flag) ans = ans*-1;
        
        if(n > 3) {
            ans = ans + (n-3);
        }
        
        return ans;
    }
    
    int clumsy(int n) {
        int op = 0;
        int ans = calc(n, false);
        
        for(int i = n-4; i >= 1; i -= 4) {
            ans += calc(i);
        }
        
        return ans;
    }
};