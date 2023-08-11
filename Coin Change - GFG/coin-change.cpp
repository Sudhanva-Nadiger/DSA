//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int count(int coins[], int N, int sum) {
        long long dp[N+1][sum+1];
        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;
        for(int i = 1; i <= N; i++) {
            dp[i][0] = 1;
            for(int t = 1; t <= sum; t++) {
                if(coins[i-1] <= t) {
                    dp[i][t] = dp[i][t-coins[i-1]];
                }
                
                dp[i][t] += dp[i-1][t];
            }
        }
        
        return dp[N][sum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends