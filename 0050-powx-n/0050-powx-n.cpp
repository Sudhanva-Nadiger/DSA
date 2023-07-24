class Solution {
public:
    double f(double x, double n) {
        if(n == 0) return 1;
        
        double t = f(x, n/2);
        
        if((int)n%2 == 0) return t*t;
        
        return t*t*x;
    }
    
    double myPow(double x, int n) {
        if(n == 0) return 1;
        
        bool flag = n < 0;
        n = abs(n);
        
        auto ans = f(x, n);
        
        if(flag) return 1/ans;
        
        return ans;
    }
};