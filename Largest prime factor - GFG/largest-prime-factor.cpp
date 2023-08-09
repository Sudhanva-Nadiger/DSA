//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public: 
    bool isPrime(int n) {
        int c = 0;
        
        for(int i = 1; i*i <= n; i++) {
            if(n%i == 0) {
                c += 2;
            }
        }
        
        return c == 2;
    }
    long long int largestPrimeFactor(int N){
        
        int ans = 0;
        for(int i = 1; i*i <= N; i++) {
            if(N%i == 0) {
                if(isPrime(i)) {
                    ans = max(ans, i);
                }
                
                int t = N/i;
                if(isPrime(t)) {
                    ans = max(ans, t);
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
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends