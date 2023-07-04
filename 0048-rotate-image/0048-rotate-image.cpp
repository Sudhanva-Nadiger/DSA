class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        for(int i = 0; i < n; i++) {
            int j = i+1;
            int k = i+1;
            
            while(j < n) {
                swap(matrix[i][j], matrix[k][i]);
                j++;
                k++;
            }
        }
        
        for(int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};