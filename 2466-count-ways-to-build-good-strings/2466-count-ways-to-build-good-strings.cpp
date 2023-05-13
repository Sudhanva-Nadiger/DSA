class Solution {
public:
    int mod = 1e9+7;
    int dp[(int)1e5+1];
    int f(int l,int h, int z, int o, int len) {
        if(len > h) {
            return 0;
        }
        
        if(dp[len] != -1) {
            return dp[len];
        }
        
        long long int uppendO = f(l, h, z, o, len + o);
        
        if(len+o >= l and len+o <= h) {
            uppendO++;
        }
        
        long long int uppendZ = f(l, h, z, o, len + z);
        
        if(len+z >= l and len+z <= h) {
            uppendZ++;
        }
        
        return dp[len] = (uppendZ + uppendO)%mod;
        
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        memset(dp, -1, sizeof(dp));
        return f(low, high, zero, one, 0);
    }
};