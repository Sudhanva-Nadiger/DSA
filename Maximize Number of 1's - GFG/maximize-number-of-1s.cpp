//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
public:
    // m is maximum of number zeroes allowed to flip
    // n is size of array
    int findZeroes(int arr[], int n, int m) {
        int j = 0;
        
        int count = 0;
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            if(arr[i] ==0) {
                count++;
            }
            
            while(count > m) {
                if(arr[j] ==0) {
                    count--;
                }
                j++;
            }
            
            ans = max(ans, i-j+1);
        }
        return ans;
    }  
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i, m;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> m;
        Solution ob;
        auto ans = ob.findZeroes(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends