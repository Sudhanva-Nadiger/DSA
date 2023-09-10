//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int CountPS(char S[], int N);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        char S[N+1];
        cin>>S;
        cout<<CountPS(S,N)<<endl;
    }
    return 0;
}


// } Driver Code Ends


int CountPS(char S[], int N)
{
    int dp[N+1][N+1];
    memset(dp, 0, sizeof dp);
    int ans = 0;
    
    for(int g = 0; g < N; g++) {
        for(int i = 0, j = g; j < N; j++, i++) {
            if(g == 0) {
                dp[i][j] = 1;
            } else if(g == 1) {
                dp[i][j] = (S[i] == S[j]);
            } else {
                dp[i][j] = ((S[i] == S[j]) && (dp[i+1][j-1]> 0));
            }
            
            ans += (dp[i][j]);
        }
    }
    
    return ans-N;
}