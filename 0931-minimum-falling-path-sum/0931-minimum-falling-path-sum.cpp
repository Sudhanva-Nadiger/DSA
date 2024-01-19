class Solution {
public:
    int solve(vector<vector<int>>& grid) {
        const int n = grid.size();
        vector<int> dCol = {-1,0,1};
        int dp[n+1][n+1];
        
        for(int j = 0; j < n; j++) {
            dp[n-1][j] = grid[n-1][j];
        }
        
        int res = 1e9;
        
        for(int row = n-2; row >= 0; row--) {
            for(int col = 0; col < n; col++) {
                int ans = 1e9;
                
                for(int i = 0; i < 3; i++){
                    int newCol = col +dCol[i];

                    if(newCol >= 0 and newCol < n){
                        int sum = grid[row][col] + dp[row+1][newCol];
                        ans = min(ans,sum);
                    }
                }
                
                dp[row][col] = ans;
            }
        }
        
        for(int i = 0; i < n; i++)
            res = min(res, dp[0][i]);
        
        
        return res;
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        return solve(matrix);
    }
};