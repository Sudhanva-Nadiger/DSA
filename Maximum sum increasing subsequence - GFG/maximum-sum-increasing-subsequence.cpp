//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    int dp[n];
	    memset(dp, 0, sizeof dp);
	    int ans = 0;
	    for(int i = 0; i < n; i++) {
	        dp[i] = arr[i];
	        for(int p = 0; p < i; p++) {
	            if(arr[i] > arr[p] && dp[i] < dp[p]+arr[i]) {
	                dp[i] = dp[p] + arr[i];
	            }
	        }
	        
	        ans =max(ans, dp[i]);
	    }
	    
	    return ans;
	}  
	
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends