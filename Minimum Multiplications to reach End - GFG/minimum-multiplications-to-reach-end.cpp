//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        queue<pair<int, int>> q;
        q.push({start, 0});
        
        int mod =  100000;
        vector<int> visited(mod+1);
        visited[start] = 1;
        
        while(q.size()) {
            auto front = q.front();
            q.pop();
            
            if(front.first == end) {
                return front.second;
            }
            
            for(auto it : arr) {
                int next = (it*front.first)%mod;
                if(!visited[next]) {
                    visited[next] = 1;
                    q.push({next, front.second+1});
                }
            }
        }
        
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends