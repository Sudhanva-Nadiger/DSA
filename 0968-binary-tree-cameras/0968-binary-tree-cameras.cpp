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
    int f(TreeNode* root, int& ans) {
        if(!root) return 1;
        
        int lc = f(root->left, ans);
        int rc = f(root->right, ans);
        
        if(lc == -1 || rc == -1) {
            ans++;
            return 0;
        }
        
        if(lc == 0  || rc == 0) {
            return 1;
        }
        
        return -1;
    }
    int minCameraCover(TreeNode* root) {
        int ans = 0;
        if(f(root, ans)==-1) ans++;
        return ans;
    }
};