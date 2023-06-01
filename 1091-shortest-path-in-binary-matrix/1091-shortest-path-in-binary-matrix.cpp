class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        if(grid[0][0] == 1) {
            return -1;
        }
        
        if(grid[m-1][n-1] == 1) {
            return -1;
        }
        
        int ans = INT_MAX;
        
        queue<pair<pair<int,int>, int>> q;
        
        q.push({{0, 0}, 1});
        grid[0][0] = 1;
        
        vector<int> dx = {0, -1,-1, -1,0, 1,1, 1}, dy = {-1, -1, 0, 1,1,1, 0, -1};
        
        
        while(q.size()) {
            auto front = q.front();
            q.pop();
            
            int row = front.first.first;
            int col = front.first.second;
            int count = front.second;
            
            if(row == m-1 and col == n-1) {
                ans = min(ans, count);   
            }else {
                
                for(int i =0; i < 8; i++) {
                    int nrow = row + dx[i];
                    int ncol = col + dy[i];
                            if(nrow >=0 and ncol >= 0 and nrow < m and ncol < n and grid[nrow][ncol] == 0) {
                                grid[nrow][ncol] = 1;
                                
                                q.push({{nrow, ncol}, count+1});
                            }
                }
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};