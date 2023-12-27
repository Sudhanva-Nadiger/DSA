class Solution {
public:
    vector<int> dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};
    
    bool canMove(vector<vector<int>>& grid, int ni, int nj) {
        return ni >= 0 && nj >= 0 && ni < grid.size() && nj < grid[0].size() && grid[ni][nj];
    }
    
    void computeDistance(vector<vector<int>>& grid, vector<vector<int>>& dist, int i, int j) {
        dist[i][j] = 0;
        queue<pair<int, int>> q;
        q.push({i, j});
        
        while(q.size()) {
            auto [i, j] = q.front();
            q.pop();
            
            for(int k = 0; k < 4; k++) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                
                if(canMove(grid, ni, nj) && dist[ni][nj] > dist[i][j] +1 ) {
                    dist[ni][nj] = dist[i][j] + 1;
                    q.push({ni, nj});
                }
            }
        }
    }
    
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, 1e9));
        computeDistance(grid, dist, start[0], start[1]);
        vector<vector<int>> temp;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] >= pricing[0] && grid[i][j] <= pricing[1] && dist[i][j] != 1e9) {
                    temp.push_back({i, j});
                }
            }
        }
        
        sort(temp.begin(), temp.end(), [&dist, &grid](vector<int>& a, vector<int>& b){
            int i1 = a[0], j1 = a[1], i2 = b[0], j2 = b[1];
            if(dist[i1][j1] != dist[i2][j2]) {
                return dist[i1][j1] < dist[i2][j2];
            }
            
            if(grid[i1][j1] != grid[i2][j2]) {
                return grid[i1][j1] < grid[i2][j2];
            }
            
            if(i1 != i2) {
                return i1 < i2;
            }
            
            return j1 < j2;
        });
        
        vector<vector<int>> ans;
        
        for(int i =0; i < min(k, (int)temp.size()); i++) {
            ans.push_back(temp[i]);
        }
        
        return ans;
    }
};