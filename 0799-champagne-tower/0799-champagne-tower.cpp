class Solution {
public:
    vector<vector<double>> dp;
    double solve(int row,int col){
        if(row < 0 or col < 0 or col > row){
            return 0.0;
        }
        
        if(dp[row][col] > -1){
            return dp[row][col];
        }
        
        double left = solve(row-1,col-1);
        double right = solve(row-1,col);
        
        return dp[row][col] = max(0.0,(left-1)/2.0)+max(0.0,(right-1)/2.0);
    }
    double champagneTower(int poured, int r, int c) {
        dp = vector<vector<double>>(r+1,vector<double>(c+1,-1.0));
        dp[0][0] = poured;
        return min(1.0,solve(r,c));
    }
};