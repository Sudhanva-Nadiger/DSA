//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    using p = pair<int, pair<int, int>>;
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<p, vector<p>, greater<p>> pq;
        for(int i = 0;  i < K ; i++) {
            pq.push({arr[i][0], {i, 0}});
        }
        
        vector<int> ans;
        
        while(pq.size()) {
            auto t = pq.top();
            pq.pop();
            
            ans.push_back(t.first);
            int row = t.second.first;
            int col = t.second.second;
            
            if(col+1 < arr[row].size()) {
                pq.push({arr[row][col+1], {row, col+1}});
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
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends