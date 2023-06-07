class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        
        for(int i = 0; i < 32; i++) {
            int cThCurrBit = c&(1<<i);
            int aThCurrBit = a&(1<<i);
            int bThCurrBit = b&(1<<i);
            
            if(cThCurrBit) {
                if(!aThCurrBit and !bThCurrBit) {
                    ans++;
                }
            }else {
                if(aThCurrBit) {
                    ans++;
                }
                if(bThCurrBit) {
                    ans++;
                }
            }
        }
        
        return ans;
    }
};