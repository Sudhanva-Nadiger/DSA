class Solution {
public:
    int f(vector<vector<int>>& grid, int i, int j, int m, int n) {
        if(j-1 < 0 or j+1 >= n or i+2 >= m or i+1 >= m) {
            return 0;
        }
        
        int sum = 0;
        
        // top horozontal
        sum += grid[i][j-1] + grid[i][j+1];
        
        // vertical
        sum += grid[i][j] + grid[i+1][j] + grid[i+2][j];
        
        // lower horizontal
        sum += grid[i+2][j-1] + grid[i+2][j+1];
        
        return sum;
    }
    int maxSum(vector<vector<int>>& grid) {
        int ans = 0;
        
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j <n; j++) {
                ans = max(ans, f(grid, i, j, m, n));
            }
        }
        
        return ans;
    }
};