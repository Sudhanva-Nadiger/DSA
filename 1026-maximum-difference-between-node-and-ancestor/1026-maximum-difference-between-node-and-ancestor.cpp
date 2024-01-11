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
    void f(TreeNode* root, int mini, int maxi) {
        if(!root) return;
        
        if(mini != 1e9) {
            ans = max(ans, abs(root->val - mini));
        }
        
        if(maxi != -1e9) {
            ans = max(ans, abs(root->val - maxi));
        }
        mini = min(mini, root->val);
        maxi = max(maxi, root->val);
        
        f(root->left, mini, maxi);
        f(root->right, mini, maxi);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        f(root, 1e9, -1e9);
        return ans;
    }
};