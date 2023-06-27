//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int getX(int n) {
        int i = 0;
        
        while((1<<i) <= n) {
            i++;
        }
        
        return i-1;
    }
    int countBits(int n){
        if(n == 1 || n == 0) {
            return n;
        } 
        
        int x = getX(n);
        
        int ans = (1<<(x-1))*x +(n-(1<<x)+1) + countBits(n-(1<<x));
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.countBits(N)<<"\n";
    }
    return 0;
}
// } Driver Code Ends