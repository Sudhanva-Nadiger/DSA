class Solution {
public:
    int numberOfChild(int n, int k) {
        int t = n-1;
        int m = k/t;
        int r = k%t;
        
        if(m&1) {
            // decreasing
            return n - r - 1;
        }
        
        return r;
    }
};