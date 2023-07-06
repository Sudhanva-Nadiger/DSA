//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int m = grid.size();
	    int n = grid[0].size();
	    
	    vector<vector<int>> dist(m, vector<int>(n, 1e9));
	    queue<pair<pair<int, int>,int>> q; // i,j distnace
	    
	    for(int i = 0; i < m; i++) {
	        for(int j = 0; j < n; j++) {
	            if(grid[i][j] == 1) {
	                q.push({{i, j}, 0});
	                dist[i][j]= 0;
	            }
	        }
	    }
	    
	    int dx[4] = {1,-1, 0, 0}, dy[4] = {0, 0, -1, 1};
	    
	    while(q.size()) {
	        auto front = q.front();
	        q.pop();
	        
	        int i = front.first.first;
	        int j = front.first.second;
	        int d = front.second;
	        
	        for(int k = 0; k < 4;  k++) {
	            int ni = i + dx[k];
	            int nj = j + dy[k];
	            
	            if(0<=ni && 0<= nj && ni<m && nj<n) {
	                int wt = abs(i-ni) + abs(j-nj);
	                if(dist[ni][nj] > d+wt) {
	                    dist[ni][nj] = d+wt;
	                    q.push({{ni, nj}, dist[ni][nj]});
	                }
	            }
	        }
	    }
	    
	    return dist;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends