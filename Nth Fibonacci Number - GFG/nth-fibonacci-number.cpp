//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int nthFibonacci(long long int n){
       int mod = 1000000007;
       
       long long int prev1 = 1;
       long long int prev2 = 1;
       
       if(n == 1 or n == 2){
           return 1;
       }
       
       for(long long int i = 3;i<=n;i++){
           long long int ans = prev1%mod + prev2%mod;
           prev2 = prev1%mod;
           prev1 = ans%mod;
       }
       
       return prev1%mod;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends