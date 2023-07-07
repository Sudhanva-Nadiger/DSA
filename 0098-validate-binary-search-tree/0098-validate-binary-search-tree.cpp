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
    bool solve(TreeNode* root,TreeNode* min,TreeNode* max){
        if(!root){
            return true;
        }
        
        if(min and root->val <= min->val){
            return false;
        }
        
        if(max and max->val <= root->val){
            return false;
        }
        
        bool l = solve(root->left,min,root);
        if(!l){
            return false;
        }
        return solve(root->right,root,max);
        
    }
    bool isValidBST(TreeNode* root) {
        return solve(root,NULL,NULL);
    }
};