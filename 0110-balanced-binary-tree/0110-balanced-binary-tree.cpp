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
    pair<int, bool> f(TreeNode* root) {
        if(!root) {
            return {0, true};
        }
        
        auto l = f(root->left);
        auto r = f(root->right);
        
        if(!l.second || !r.second) {
            return {-1, false};
        }
        
        
        return {max(l.first, r.first)+1, (abs(l.first-r.first) <= 1)};
    }
    bool isBalanced(TreeNode* root) {
        return f(root).second;
    }
};