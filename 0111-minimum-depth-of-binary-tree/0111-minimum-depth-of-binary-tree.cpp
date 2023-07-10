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
    int ans = 1e9;
    void f(TreeNode* root, int count) {
        if(!root) return ;
        
        if(!root->left && !root->right) {
            ans = min(ans, count+1);
        }
        
        f(root->left, count+1);
        f(root->right, count+1);
    }
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        f(root, 0);
        return ans;
    }
};