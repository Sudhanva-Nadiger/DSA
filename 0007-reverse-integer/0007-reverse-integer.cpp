class Solution {
public:
    int reverse(int n) {
        long long x = (long long)(n);
        bool isNegative = (x<0);
        x = abs(x);
        
        long long int rev = 0ll;
        
        while(x) {
            rev = rev*10 + (long long)x%10;
            x /= 10;
            
            if(rev > INT_MAX) {
                return 0;
            }
        }
        
        return isNegative ? -rev : rev;
    }
};