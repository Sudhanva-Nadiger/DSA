class Solution {
public:
    vector<int> dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};
    int dp[201][201];
    int dfs(vector<vector<int>>& matrix, int i, int j) {
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = 1;
        
        for(int k = 0; k < 4; k++) {
            int ni = i+dx[k];
            int nj = j+dy[k];
            
            if(ni >= 0 && nj >= 0 && ni < matrix.size() && nj < matrix[0].size() && matrix[ni][nj] > matrix[i][j]) {
                int t = 1 + dfs(matrix, ni, nj);
                ans = max(ans, t);
            }
        }
        
        return dp[i][j] = ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        memset(dp, -1, sizeof(dp));
        
        int ans = 0;
        
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                ans = max(ans, dfs(matrix, i, j));
            }
        }
        
        return ans;
    }
};