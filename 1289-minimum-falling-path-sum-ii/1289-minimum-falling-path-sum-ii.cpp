class Solution {
public:
    int dp[201][202];
    
    int f(vector<vector<int>>& grid, int row, int prevCol) {
        if(row == grid.size()) return 0;
        
        int& st = dp[row][prevCol+1];
        
        if(st != -1) return st;
        
        int ans = 1e9;
        for(int col = 0; col < grid[0].size(); col++) {
            if(col == prevCol) continue;
            
            int t = grid[row][col] + f(grid, row+1, col);
            ans = min(ans, t);
        }
        
        return st = ans;
    }
    
    int minFallingPathSum(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof dp);
        int ans = INT_MAX;
        
        for(int i = 0; i < grid[0].size(); i++) {
            ans = min(ans, grid[0][i] + f(grid, 1, i));
        }
        
        return ans;
    }
};