class Solution {
public:
    int kthFactor(int n, int k) {
        if(2*sqrt(n) <= k) return -1;
        
        int i;
        
        for(i = 1; i <= n && k > 0; i++) {
            if(n%i == 0){
                k--;
            }
            
            if(k == 0) return i;
        }
        
        return -1;
    }
};