class Solution {
public:
    int m, n;
    int dp[51][51][101];
    int visited[51][51];
    int f(vector<vector<int>>& grid, int i, int j, int health) {
        if(i >= m || j >= n || i < 0 || j < 0 || health <= 0 || visited[i][j]) {
            return 0;
        }    
        
        if(grid[i][j]) {
            health -= 1;
        }
        
        if(i == m-1 && j == n-1) {
            return health >= 1;
        }
        
        int& st = dp[i][j][health];
        
        if(st != -1) return st;
        
        visited[i][j] = 1;
        
        int left = f(grid, i, j-1, health);
        int right = f(grid, i, j+1, health);
        int down = f(grid, i+1, j, health);
        int up = f(grid, i-1, j, health);
        
        visited[i][j] = 0;
        
        return st = left || right || down || up;
    }
    
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        m = grid.size();
        n = grid[0].size();
        
        memset(dp, -1, sizeof dp);
        memset(visited, 0, sizeof visited);
        
        return f(grid, 0, 0, health);
    }
};