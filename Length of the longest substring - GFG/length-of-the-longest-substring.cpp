//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string str){
        int j = 0;
        vector<int> mp(26);
        int ans = -1;
        int n = str.size();
        
        int count = 0;
        
        for(int i = 0; i < n; i++) {
           if( mp[str[i]-'a'] == 0) {
               count++;
           }
           
           mp[str[i]-'a'] ++;
            
            int sz = i-j+1;
            if(sz != count) {
                mp[str[j]-'a']--;
                if(mp[str[j]-'a'] == 0) {
                    count--;
                }
                j++;
            }else {
                ans = max(ans, sz);
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
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends