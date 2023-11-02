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
    int sum(TreeNode* root,int* count,int &ans){
        if(!root){
            *count = 0;
            return 0;
        }
        int lc = 0,rc = 0;
        int left = sum(root->left,&lc,ans);
        int right = sum(root->right,&rc,ans);
        *count = 1+lc+rc;
        int total = left + right + root->val;
        int avg = (int)total / *count;
        
        ans += (avg == root->val);
        
        return total;
        
        
    }
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        int count = 0;
        sum(root,&count,ans);
        return ans;
    }
};