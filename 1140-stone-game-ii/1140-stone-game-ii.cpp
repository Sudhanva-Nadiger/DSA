class Solution {
public:
    int dp[101][1000][2];
    int f(vector<int>& piles,int start, int m, int player) {
        if(start >= piles.size()) return 0;
        
        if(dp[start][m][player] != -1) return dp[start][m][player];
    
        int ans = 0;
        
        if(player == 0) ans = INT_MAX;
        
        for(int index = start, x = 1; index < piles.size() && x <= 2*m; index++, x++) {
            int j = start;
            int t = 0;
            while(j <= index) {
                t += (player == 1 ? piles[j] : 0);
                j++;
            }

            t += f(piles, index+1, max(m, x), !player);
            
            if(player) {
                ans = max(ans, t);
            }else {
                ans = min(ans, t);
            }
        }
        
        return dp[start][m][player] = ans;
    }
    
    
    int stoneGameII(vector<int>& piles) {
        memset(dp, -1, sizeof(dp));
        return f(piles, 0, 1, 1);
    }
};