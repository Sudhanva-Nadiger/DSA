//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int dp[100][100][201];
    bool f(string& a, string& b, string& c, int i, int j, int k) {
        if(k == c.size()) {
            return i == a.size() && j == b.size();    
        }
        
        if(i == a.size()) {
            return b.substr(j) == c.substr(k);
        }
        
        if(j == b.size()) {
            return a.substr(i) == c.substr(k);
        }
        
        int& st = dp[i][j][k];
        
        if(st != -1) return st;
        
        if(a[i] == c[k] && b[j] == c[k]) {
            return st = f(a, b, c, i+1, j, k+1) || f(a, b, c, i, j+1, k+1);
        }
        
        if(a[i] == c[k]) {
            return st = f(a, b, c, i+1, j, k+1);
        }
        
        if(b[j] == c[k]) {
            return st = f(a, b, c, i, j+1, k+1);
        }
        
        return st = false;
    }
    bool isInterleave(string A, string B, string C) 
    {
        memset(dp, -1, sizeof dp);
        return f(A, B, C, 0, 0, 0);
    }

};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}
// } Driver Code Ends