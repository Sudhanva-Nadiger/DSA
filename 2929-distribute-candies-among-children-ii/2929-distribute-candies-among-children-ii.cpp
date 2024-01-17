class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans = 0;
        for(int i = 0; i <= min(limit, n); i++) {
            int rem = n-i;
            
            if(rem <= limit) {
                ans += rem+1;
            } else if(rem <= 2*limit) {
                ans += limit - (rem-limit) + 1;
            }
        }
        
        return ans;
    }
};