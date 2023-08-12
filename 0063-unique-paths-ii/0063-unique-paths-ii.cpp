class Solution {
public:
    int solve(vector<vector<int>>&grid,int i,int j,vector<vector<int>>&dp){
        if(i == grid.size()-1 and j == grid[0].size()-1 and grid[i][j] != 1){
            return 1;
        }
        if(i>=grid.size() or j>=grid[0].size()){
            return 0;
        }
        if(grid[i][j] == 1){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int downPaths = solve(grid,i+1,j,dp);
        int leftPaths = solve(grid,i,j+1,dp);
        
        return dp[i][j] = downPaths+leftPaths;
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(101,vector<int>(101,-1));
        return solve(obstacleGrid,0,0,dp);
    }
};