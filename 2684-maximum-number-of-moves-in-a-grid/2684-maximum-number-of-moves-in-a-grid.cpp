class Solution {
public:
    int dp[1001][1001];
    int f(vector<vector<int>>& grid, int row, int col = 0) {
        
        if(dp[row][col] != -1) {
            return dp[row][col];
        }
        
        int top = 0;
        
        if(row-1 >= 0 and col + 1 < grid[0].size()) {
            if(grid[row][col] < grid[row-1][col+1]){
                top = 1+f(grid, row-1, col+1);
            }
        }
        
        int next = 0;
        
        if(col+1 < grid[0].size()) {
            if(grid[row][col] < grid[row][col+1]) {
                next = 1 + f(grid, row, col+1);
            }
        }
        
        int down = 0;
        
        if(row+1 < grid.size() and col+1 < grid[0].size()) {
            if(grid[row][col] < grid[row+1][col+1]) {
                down = 1+f(grid, row+1, col+1);
            }
        }
        
        return dp[row][col] = max(top, max(next, down));
    }
    
    int maxMoves(vector<vector<int>>& grid) {
        int ans = 0;
        memset(dp, -1, sizeof(dp));
        for(int row = 0; row < grid.size(); row++) {
            int temp = f(grid, row);
            ans = max(ans, temp);
        }
        
        return ans;
    }
};