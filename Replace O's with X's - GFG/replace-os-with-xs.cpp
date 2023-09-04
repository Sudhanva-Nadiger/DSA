//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};
    void dfs(vector<vector<char>>& mat, int i, int j, vector<vector<int>>& visited) {
        visited[i][j] = 1;
        
        for(int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            
            if(ni >= 0 && nj >= 0 && ni < mat.size() && nj < mat[0].size() && 
                                                    mat[ni][nj] == 'O' && !visited[ni][nj]) {
                dfs(mat, ni, nj, visited);
            } 
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<int>> visited(n, vector<int>(m, 0));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 || j == 0 || i == n-1 || j == m-1) {
                    if(!visited[i][j] && mat[i][j] == 'O') {
                        dfs(mat, i, j, visited);
                    }
                }
            }
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 'O' && !visited[i][j]) {
                    mat[i][j] = 'X';
                }
            }
        }
        
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends