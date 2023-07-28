//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
       if(A[0][0] == 0) return -1;
       vector<vector<int>> dist(N, vector<int>(M, 1e9));
       queue<pair<int, int>> q;
       
       vector<int> dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};
       
       q.push({0, 0});
       dist[0][0] = 0;
       
       while(q.size()) {
           auto front = q.front();
           int i = front.first;
           int j = front.second;
           q.pop();
           
           for(int k = 0; k < 4; k++) {
               int ni = i + dx[k];
               int nj = j + dy[k];
               
               if(ni >= 0 && nj >= 0 && ni < N && nj < M && A[ni][nj] == 1) {
                   if(dist[ni][nj] > dist[i][j] + 1) {
                       dist[ni][nj] = dist[i][j] + 1;
                       q.push({ni, nj});
                   }
               }
           }
       }
       
       if(dist[X][Y] >= 1e9) return -1;
       
       return dist[X][Y];
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends