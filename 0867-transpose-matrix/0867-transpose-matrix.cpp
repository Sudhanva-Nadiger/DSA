class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n;  j++) {
                ans[j][i] = mat[i][j];
            }
        }
        
        return ans;
    }
};