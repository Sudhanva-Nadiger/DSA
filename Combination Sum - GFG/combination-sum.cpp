//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    
    vector<vector<int>> ans;
    vector<int> arr;
    
    void f(vector<int>& nums, int i, int target) {
        if(target < 0) return;
        
        if(target == 0) {
            ans.push_back(arr);
            return;
        }
        
        if(i == nums.size()) return;
        
        
        arr.push_back(nums[i]);
        f(nums, i, target-nums[i]);
        arr.pop_back();
        
        int j = i;
        while(i < nums.size() && nums[i] == nums[j]) {
            i++;
        }
    
        
        f(nums, i, target);
    }
    
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        sort(begin(A), end(A));
        f(A, 0, B);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends