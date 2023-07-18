//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string& s, string& p)
    {
       int count = p.size();
       if(count > s.size()) return "-1";
       
       int mc = 0;
       
       int start = -1, end = s.size();
       
       vector<int> mp1(26);
       for(auto it : p) {
           mp1[it-'a']++;
       }
       
       vector<int> mp2(26);
       int j = 0;
       
       for(int i = 0;i < s.size(); i++) {
           if(mp1[s[i]-'a'] > 0) {
               if(mp2[s[i]-'a'] < mp1[s[i]-'a']) {
                   mc++;
               }
               
               mp2[s[i]-'a']++;
           }
           
           
           while((j <= i) && (mc == count)) {
               if((i-j+1) < (end-start+1)) {
                   start = j;
                   end = i;
               }
               if(mp1[s[j]-'a'] > 0) {
                   mp2[s[j]-'a']--;
                   
                   if(mp2[s[j]-'a'] < mp1[s[j]-'a']) {
                       mc--;
                   }
               }
               j++;
           }
       }
       
       if(start == -1) return "-1";
       
       return s.substr(start, (end-start+1));
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends