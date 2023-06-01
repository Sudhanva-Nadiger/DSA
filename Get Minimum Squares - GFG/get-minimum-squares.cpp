//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    int dp[10001];
    
    int f(int n) {
        if(n == 0) {
            return 0;
        }
        
        if(dp[n] != -1) {
            return dp[n];
        }
        
        int ans = INT_MAX;
        for(int i = 1; i*i <= n; i++) {
            int temp = 1+f(n-i*i);
            ans = min(ans, temp);
        }
        
        return dp[n] = ans;
    }
	public:
	int MinSquares(int n)
	{
	    memset(dp, -1, sizeof(dp));
	    return f(n);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.MinSquares(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends