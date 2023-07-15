//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    void f(stack<int>& st, int& n) {
        n--;
        int t = st.top();
        st.pop();
        if(n == 0) {
          return;  
        }
        
        f(st, n);
        
        st.push(t);
    }
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&st, int n)
    {
        int t = n - (n-1)/2;
        f(st, t);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends