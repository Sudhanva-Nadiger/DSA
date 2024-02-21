/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<string>ans;
    vector<string> solve(TreeNode* root,string s)
    {
        if(!root->left&&!root->right)
        {
            s+=to_string(root->val);
            ans.push_back(s);
            return ans;
        }
        
        s+=to_string(root->val)+"->";
        if(root->left)
            solve(root->left,s);
        if(root->right)
            solve(root->right,s);
        
        return ans;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string s = "";
        return solve(root,s);
    }
};