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
    int ans = 0;
    void f(TreeNode* root,int dir, int count) {
        if(!root) return;
        ans = max(ans, count);
        if(dir == 0) {
            f(root->left, -1, 1);
            f(root->right, 1, 1);
        }else if(dir == -1) {
            // i am coming from left
            
            //move to left
            f(root->left, -1, 1);
            f(root->right, 1, count+1);
        }else {
            f(root->left, -1, count+1);
            f(root->right, 1, 1);
        } 
    }
    int longestZigZag(TreeNode* root) {
        f(root, 0, 0);
        return ans;
    }
};