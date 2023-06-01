//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isPalindrome(string& s) {
        int i = 0, j = s.size()-1;
        
        while(i < j) {
            if(s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        
        return true;
    }
    
    int dp[501];
    int f(int index, string& str) {
        if(index >= str.size()) {
            return 0;
        }
        
        if(dp[index] != -1) {
            return dp[index];
        }
        
        string cs = "";
        
        int ans = 1e9;
        
        for(int i = index; i < str.size(); i++) {
            cs.push_back(str[i]);
            
            if(isPalindrome(cs)) {
                int temp = 1 + f(i+1, str);
                ans = min(ans, temp);
            }
        }
        
        return dp[index] = ans;
    }
    int palindromicPartition(string str)
    {
        memset(dp, -1, sizeof(dp));
        return f(0, str)-1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends