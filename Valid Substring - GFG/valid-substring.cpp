//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string s) {
        stack<int> st;
        st.push(-1);
        int n = s.size();
        
        for(int i = 0; i < n; i++) {
            if(st.top() != -1 && s[st.top()] == '(' && s[i] == ')') {
                st.pop();
            }else {
                st.push(i);
            }
        }
        
        int prev = n;
        int ans = 0;
        while(st.size()) {
            ans = max(ans, prev-st.top()-1);
            prev = st.top();
            st.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}

// } Driver Code Ends