//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends



class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
 		int sr = 0, sc = 0, er = n-1, ec = m-1;
 		
 		while(true) {
 		    for(int i = sc; i <= ec; i++) {
 		        k--;
 		        if(k == 0) {
 		            return a[sr][i];
 		        }
 		    }
 		    
 		    sr++;
 		    for(int i = sr; i <= er; i++) {
 		        k--;
 		        if(k == 0) {
 		            return a[i][ec];
 		        }
 		    }
 		    
 		    ec--;
 		    for(int i = ec; i >= sc; i--) {
 		        k--;
 		        if(k == 0) {
 		            return a[er][i];
 		        }
 		    }
 		    
 		    er--;
 		    for(int i = er; i >= sr; i--) {
 		        k--;
 		        if(k == 0) {
 		            return a[i][sc];
 		        }
 		    }
 		    
 		    sc++;
 		}
 		
 		return 0;
 	}
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends