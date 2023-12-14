class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size();
        int n =grid[0].size();
        
        vector<int> rowOnes(m),rowZeros(m),colOnes(n),colZeros(n);
        
        int id = 0;
        for(auto it : grid){
            int z = 0;
            int o = 0;
            for(int i : it){
                z += i==0;
                o += i==1;
            }
            rowOnes[id] = o;
            rowZeros[id++] = z;
            z = o = 0;
        }
        id = 0;
        for(int i = 0; i < n; i++){
            int z = 0;
            int o = 0;
            for(int j=0 ; j < m; j++){
                z += grid[j][i]==0;
                o += grid[j][i]==1;
            }
            
            colOnes[id] = o;
            colZeros[id++] = z;
            z = o = 0;
        }
        
        vector<vector<int>> ans = grid;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                ans[i][j] = rowOnes[i]+colOnes[j]-rowZeros[i]-colZeros[j];
            }
        }
        return ans;
    }
};