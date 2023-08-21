//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int Count(vector<vector<int> >& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int ans = 0;
        vector<int> dx = {1, -1, 0, 0, -1, -1, 1, 1}, 
                    dy = {0, 0, 1, -1, -1, 1, 1, -1};
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 1) {
                    
                    int count = 0;
                    for(int k = 0; k < 8; k++) {
                        int ni = i + dx[k];
                        int nj = j + dy[k];
                        
                        if(ni >= 0 && nj >= 0 && ni < m && nj < n) {
                            count += !matrix[ni][nj];
                        }
                    }
                    
                    ans += ((count >0) && !(count&1));
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends