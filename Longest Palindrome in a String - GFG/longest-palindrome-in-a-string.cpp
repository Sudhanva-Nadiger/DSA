//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string s) {
        int n = s.size();
        int dp[n][n];
        memset(dp, 0, sizeof dp);
        string ans = s.substr(0, 1);
        for(int g = 0; g < n; g++) {
            for(int i =0, j = g; j < n; i++, j++) {
                if(g == 0) {
                    dp[i][j] = 1;
                } else if(g == 1) {
                    if(s[i] ==s[j]) {
                        dp[i][j] = 1;
                    }
                }else {
                    if(s[i] == s[j] && dp[i+1][j-1]) {
                        dp[i][j] = 1;
                    }
                }
            }
        }
        
        for(int g = n-1; g >= 0; g--) {
            for(int i = 0, j = g; j < n; i++, j++) {
                if(dp[i][j]) {
                    return s.substr(i, g+1);
                }
            }
        }
        
        return "";
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends