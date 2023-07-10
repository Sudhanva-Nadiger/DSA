class Solution {
public:
    int dp[300][300];
    int f(vector<vector<int>>& grid, int i, int j) {
        if(i >= grid.size() || j >= grid[0].size()) {
            return 0;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int left = f(grid, i, j+1);
        int down = f(grid, i+1, j);
        int dia = f(grid, i+1, j+1);
        
        if(grid[i][j] == 1) {
            return dp[i][j] = 1+min({left, down, dia});
        }
        
        return dp[i][j] = 0;
    }
    int countSquares(vector<vector<int>>& matrix) {
        memset(dp, -1, sizeof dp);
        int ans = 0;
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++)
                ans += f(matrix, i,j);
        }
        return ans;
    }
};