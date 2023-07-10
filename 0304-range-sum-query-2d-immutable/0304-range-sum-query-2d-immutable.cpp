class NumMatrix {
    vector<vector<int>> dp;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        dp = matrix;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        for(int i = 0; i < m; i++) {
            for(int j = 1; j < n; j++) {
                dp[i][j] += dp[i][j-1];        
            }
        }
        
        for(int j = 0; j < n; j++) {
            for(int i = 1; i < m; i++) {
                dp[i][j] += dp[i-1][j];
            }
        }
        
        for(int i = 0; i < dp.size(); i++) {
            dp[i].insert(dp[i].begin(), 0);
        }
        
        vector<int> pre(n+1);
        dp.insert(dp.begin(), pre);
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2+1][col2+1] - dp[row1][col2 + 1] - dp[row2 + 1][col1] + dp[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */