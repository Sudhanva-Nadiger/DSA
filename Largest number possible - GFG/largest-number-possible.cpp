//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
        if(S == 0 and N != 1) return "-1";
        vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        reverse(arr.begin(), arr.end());
        
        string ans = "";
        for(int i = 0; i < arr.size() && N > 0 && S > 0; i++) {
            int count = S/arr[i];
            count = min(count, N);
            
            
            S -= (count*arr[i]);
            N -= count;
            
            while(count--) {
                ans.push_back((arr[i] + '0'));
            }
        }
        
        if(S != 0) return "-1";
        
        while(N-- > 0) {
            ans.push_back('0');
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends