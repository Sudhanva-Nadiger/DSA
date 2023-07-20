class Solution {
public:
    void flipRow(vector<int>& arr) {
        for(int i = 0; i < arr.size(); i++) {
            arr[i] = !arr[i];
        }
    }
    
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i = 0; i < m; i++) {
            if(grid[i][0] == 0) {
                flipRow(grid[i]);
            }
        }
        
        int ans = 0;
        int id = 0;
        
        for(int j = n-1; j >= 0; j--) {
            int f = 0;
            int nf = 0;
            
            for(int i = 0; i < m; i++) {
                f += (!grid[i][j])*(1<<id);
                nf += (grid[i][j])*(1<<id);
            }
            
            id++;
            
            ans += max(f, nf);
        }
        
        return ans;
    }
};