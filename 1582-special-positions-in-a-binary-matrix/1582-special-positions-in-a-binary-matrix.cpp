class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        vector<int> mp1(101), mp2(101);
        
        for(int i = 0; i < mat.size(); i++) {
            for(int j = 0; j < mat[0].size(); j++) {
                mp1[i] += mat[i][j];
                mp2[j] += mat[i][j];
            }
        }
        
        int ans = 0;
        for(int i = 0; i < mat.size(); i++) {
            for(int j = 0; j < mat[0].size(); j++) {
                if(mat[i][j] && mp1[i] == mp2[j] && mp1[i] == 1) {
                    ans++;
                }
            }
        }
        
        return ans;
    }
};