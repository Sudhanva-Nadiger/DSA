//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
    vector<vector<int>> nums = {
        {1,2,3},
        {4,5,6},
        {7,8,9},
        {-1,0,-1},
    };
    int dx[5] = {1, -1, 0, 0, 0};
    int dy[5] = {0, 0, 1, -1, 0};
    long long dp[10][10][50];
    
    long long f(int i, int j, int n) {
        if(n == 1) return 1;
        if(dp[i][j][n] != -1) return dp[i][j][n];
        
        long long ans = 0;
        for(int k = 0; k < 5; k++) {
            int ni = i+dx[k];
            int nj = j+dy[k];
            
            if(ni >= 0 && ni < nums.size() && nj >= 0 && nj < nums[0].size()) {
                if(nums[ni][nj] != -1) {
                    ans += f(ni, nj, n-1);
                }
            }
        }
        
        return dp[i][j][n] = ans;
    }
	long long getCount(int n)
	{
		memset(dp, -1, sizeof dp);
		long long ans = 0;
		for(int i = 0; i < nums.size(); i++) {
		    for(int j = 0; j < nums[0].size(); j++) {
		        if(nums[i][j] != -1) {
		            ans += f(i, j, n);
		        }
		    }
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

       

	    Solution ob;
	    cout << ob.getCount(n) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends