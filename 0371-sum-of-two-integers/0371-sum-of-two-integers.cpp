class Solution {
public:
    int getSum(int a, int b) {
        if(a == 0) return b;
        if(b == 0) return a;
        
        return getSum(a^b, ((unsigned int)(a&b)*2));
    }
};