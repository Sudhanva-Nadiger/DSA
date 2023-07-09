//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int nums[], int n) 
    { 
        int i = 0;
        
        while(i < n) {
            if((nums[i] == i+1) || (nums[i] > n) || (nums[i] <= 0)) {
                i++;
            }else {
                int id = nums[i]-1;
                if(nums[id] == id+1) {
                    i++;
                    continue;
                }
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        
        for(int j = 0; j < n; j++) {
            if(nums[j] != j+1) {
                return j+1;
            }
        }
        
        return n+1;
    } 
};

//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
} 
// } Driver Code Ends