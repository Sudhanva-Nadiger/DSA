class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        
        unordered_map<int, int> row, col ;
        
        for(int i = 0; i < mat.size(); i++) {
            for(int j = 0; j < mat[0].size(); j++){
                row[mat[i][j]] = i;
                col[mat[i][j]] = j;
            }
        }
        
        unordered_map<int, int> mpr, mpc;
        
        int m = mat.size();
        int n = mat[0].size();
        
        int count = 0;
        
        for(auto it : arr) {
            int r = row[it];
            int c = col[it];
            
            mpr[r] ++;
            
            if(mpr[r] >= n) {
                return count;
            }
            
            mpc[c] ++;
            
            if(mpc[c] >= m) {
                return count;
            }
            
            count++;
        }
        
        return -1;
    }
};