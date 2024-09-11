class Solution {
public:
    int minBitFlips(int start, int goal) {
        int n = start ^ goal;
        
        int ans = 0;
        
        while(n) {
            n = n&(n-1);
            ans++;
        }
        
        return ans;
    }
};