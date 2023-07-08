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
    // sum, max, min
    int ans = 0;
    vector<int> f(TreeNode* root) {
        if(!root) {
            return {0, (int)-1e9, (int)1e9};
        }
        
        auto l = f(root->left);
        auto r = f(root->right);
        
        ans = max({ans, l[0], r[0]});
        if(l[1] < root->val && root->val < r[2]) {
            return {l[0]+r[0]+root->val, max(root->val, r[1]), min(root->val,l[2])};
        }
        
        return {max(l[0], r[0]), INT_MAX, INT_MIN};
    }
    int maxSumBST(TreeNode* root) {
        return max(f(root)[0], ans);
    }
};