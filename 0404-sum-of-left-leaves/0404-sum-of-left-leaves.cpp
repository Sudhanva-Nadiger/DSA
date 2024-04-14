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
    int f(TreeNode* root, bool isLeft) {
        if(!root) return 0;
        
        if(isLeft && !root->left && !root->right) {
            return root->val;
        }
        
        return f(root->left, true)+f(root->right, false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return f(root, false);
    }
};