//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        int zor = 0;
        for(auto it : nums) zor ^= it;
        
        int id = (zor & (-zor));
        int one = 0, zero = 0;
        
        for(int it: nums) {
            if(it & id) {
                one ^= it;
            }else {
                zero ^= it;
            }
        }
        
        if(one < zero) return {one, zero};
        return {zero, one};
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends