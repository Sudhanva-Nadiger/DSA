//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        
        int mod = 1000000007;
        
        long long p = 1;
        long long pp = 2;
        long long ppp = 4;
        
        if(n == 1) return p;
        if(n == 2) return pp;
        if(n == 3) return ppp;
        
        
        for(int i = 4; i <= n; i++) {
            int ans = ((p + pp)%mod + ppp)%mod;
            p = pp;
            pp = ppp;
            ppp = ans;
        }
        
        return ppp;
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends