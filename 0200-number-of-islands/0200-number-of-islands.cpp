class Solution {
public:
    void dfs(vector<vector<char>>& adj,int i,int j){
        
        if(i>=adj.size() or i<0 or j>= adj[0].size() or j<0 or adj[i][j] != '1'){
            return;
        }
        
        adj[i][j] = '0';
        
        dfs(adj,i+1,j);
        dfs(adj,i-1,j);
        dfs(adj,i,j+1);
        dfs(adj,i,j-1);
        
        return;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for(int i = 0;i<grid.size();++i){
            for(int j = 0;j<grid[0].size();++j){
                
                if(grid[i][j] == '1'){
                    ans++;
                    dfs(grid,i,j);
                }
            }
        }
        
        return ans;
    }
        
};