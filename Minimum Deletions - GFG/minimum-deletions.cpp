//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int minimumNumberOfDeletions(string s) { 
        string r = s;
        reverse(r.begin(), r.end());
        const int n = s.size();
        int dp[n+1][n+1];
        memset(dp, 0, sizeof dp);
        
        int ans = 0;
        for(int i = n-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {
                if(s[i] == r[j]) {
                    dp[i][j] = 1 + dp[i+1][j+1];
                }
                
                dp[i][j] = max({dp[i][j], dp[i+1][j], dp[i][j+1]});
                
                ans = max(ans, dp[i][j]);
            }
        }
        
        return n-ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends