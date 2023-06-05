class Solution {
public:
    int smallestRepunitDivByK(int k) {
        long long int r = 1;
        
        for(int i =1 ; i <= k; i++) {
            if(r%k == 0) {
                return i;
            }
            
            r = (r*10 + 1)%k;
        }
        
        return -1;
    }
};