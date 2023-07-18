//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    int index = 0;
    Node* f(int l, int r,int pre[], int in[]) {
        if(l > r) return NULL;
        
        Node* root = new Node(pre[index]);
        index++;
        if(l == r) return root;
        
        int mid = r;
        
        for(int i = l; i <= r; i++) {
            if(in[i] == root->data) {
                mid = i;
                break;
            }
        }
        
        root->left = f(l, mid-1, pre, in);
        root->right = f(mid+1, r, pre, in);
        
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
       
        return f(0, n-1, pre, in);
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends