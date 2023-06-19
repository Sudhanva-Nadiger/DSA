class Solution {
public:
    int dp[1001][1001];
    int mod = 1e9+7;
    vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
    int f(vector<vector<int>>& grid, int i, int j) {
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = 0;
        
        for(int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            
            if(ni >= 0 && nj >= 0 && ni < grid.size() && nj < grid[0].size()) {
                if(grid[ni][nj] > grid[i][j]) {
                    ans %= mod;
                    ans += f(grid, ni, nj)%mod;
                }
            }
        }
        
        return dp[i][j] = (ans+1)%mod;
    }
    int countPaths(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        int ans = 0;
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[0].size(); j++) {
                ans = (ans + f(grid, i, j)%mod)%mod;
            }
        return ans%mod;
    }
};