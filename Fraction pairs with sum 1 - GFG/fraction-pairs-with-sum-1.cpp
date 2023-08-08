//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countFractions(int n, int numerator[], int denominator[])
    {
        unordered_map<int, unordered_map<int, int>> mp;
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            int g = __gcd(numerator[i], denominator[i]);
            
            int a = numerator[i]/g;
            int b = denominator[i]/g;
            
            if(mp[b].count(b-a)) {
                ans+= mp[b][b-a];
            }
            
            mp[b][a]++;
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
        int n;
        cin>>n;
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends