class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        long long num = 0;
        int d = x;
        while(d) {
            num = num*10 + d%10;
            d /= 10;
        }
        
        return x == num;
    }
};