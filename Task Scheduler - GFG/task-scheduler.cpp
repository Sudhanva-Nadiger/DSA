//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int leastInterval(int N, int K, vector<char> &tasks) {
        unordered_map<char, int> mp;
        
        for(auto it : tasks) {
            mp[it]++;
        }
        
        priority_queue<int> pq;
        for(auto it : mp) pq.push(it.second);
        
        int t = 0;
        queue<pair<int, int>> q;
        
        while(q.size() || pq.size()) {
            t += 1;
            
            if(pq.size()) {
                int top = pq.top()-1;
                pq.pop();
                if(top> 0) {
                    q.push({top, t+K});
                }
            }
            
            if(q.size() && q.front().second == t) {
                pq.push(q.front().first);
                q.pop();
            }
        }
        
        return t;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<char> tasks(N);
        for (int i = 0; i < N; i++) cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}
// } Driver Code Ends