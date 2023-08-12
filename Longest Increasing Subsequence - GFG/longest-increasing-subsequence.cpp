//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       vector<int> arr;
       arr.push_back(a[0]);
       
       for(int i = 1; i < n; i++) {
           if(arr.back() < a[i]) {
               arr.push_back(a[i]);
           }else {
               int id = lower_bound(arr.begin(), arr.end(), a[i])-arr.begin();
               arr[id] = a[i];
           }
       }
       
       return arr.size();
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends