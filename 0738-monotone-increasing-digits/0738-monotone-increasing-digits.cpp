class Solution {
public:
    #define ll long long
    
    ll ans = 0;
    void f(ll n, ll num) {
        if(num <= n) {
            ans = max(ans, num);
        } else {
            return;
        }
        
        ll lastDig = num%10;
        if(lastDig == 0) {
            lastDig = 1;
        }
        
        for(ll i = lastDig; i <= 9; i++) {
            ll newNum = num*10 + i;
            f(n, newNum);
        }
        
        return;
    }
    
    int monotoneIncreasingDigits(int n) {
        f(n, 0ll);
        return ans;
    }
};