//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    unordered_map<char, int> mp;
		    queue<char> pq;
		    string ans = "";
		    
		    for(int i = 0; i < A.size(); i++) {
		        mp[A[i]]++;
		        pq.push(A[i]);
		        
		        while(pq.size() && mp[pq.front()] > 1) {
		            pq.pop();
		        }
		        
		        if(pq.size()) {
		            ans.push_back(pq.front());
		        }else {
		            ans.push_back('#');
		        }
		    }
		    
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends