class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n=mat[0].size();
		
		// Attaching its positions tag before sorting
        for(int i=0; i<mat.size(); i++){
            mat[i].push_back(i);
        }
        
		// Applying sort function on whole 2D vector
		// Sorting goes like taking each row as a number and sorts in ascending order
        sort(mat.begin(), mat.end());
        vector<int> ans(k);
        
		// The last tagged positions are required
        for(int i=0; i<k; i++){
            ans[i]=mat[i][n];            
        }
        return ans;
    }
};