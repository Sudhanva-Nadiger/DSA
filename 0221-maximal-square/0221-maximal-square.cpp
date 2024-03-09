class Solution {
public:
    int dp[301][301];
    int result = 0;
    int f(vector<vector<char>>& grid, int i, int j) {
        if(i >= grid.size() || j >= grid[0].size()) return 0;
        
        int& st = dp[i][j];
        
        if(st != -1) return st;
        
        if(grid[i][j] == '0') return st = 0;
        
        int right = f(grid, i+1, j);
        int down = f(grid, i, j+1);
        int diag = f(grid, i+1, j+1);
        
        st = 1 + min({right, down, diag});
        
        result = max(result, st);
        return st;
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        memset(dp, -1, sizeof dp);
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                f(matrix, i, j);
            } 
        }
        return result*result;
    }
};