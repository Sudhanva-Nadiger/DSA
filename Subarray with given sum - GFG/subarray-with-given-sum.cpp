//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    
    vector<int> subarraySum(vector<int>& arr, int n, long long s)
    {
        if(s == 0){
            return {-1};
        }
        int j = 0;
        long long sum = 0;
        for(int i = 0;i<n;i++){
            while(sum > s){
                sum -= arr[j];
                j++;
            }
            
            if(sum == s){
                return {j+1,i};
            }
            
            sum += arr[i];
            
        }
        while(sum > s){
            sum -= arr[j];
            j++;
        }
        if(sum == s){
            return {j+1,n};
        }
        
        return {-1};
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
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends