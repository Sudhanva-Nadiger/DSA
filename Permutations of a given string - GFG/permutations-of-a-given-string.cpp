//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    vector<string> ans;
	    unordered_set<string> st;
	    void f(string s, string perm) {
	        if(s.size() == 0) {
	            st.insert(perm);
	            return;
	        }
	        
	        for(int i = 0; i < s.size(); i++) {
	            string str = perm;
	            str.push_back(s[i]);
	            string l = s.substr(0, i);
	            string r = s.substr(i+1);
	            
	            string rfs = l+r;
	            
	            f(rfs,str);
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    f(S, "");
		    for(auto it : st) ans.push_back(it);
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends