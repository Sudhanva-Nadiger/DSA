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
    int minDepth(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        int lh = minDepth(root->left);
        int rh=minDepth(root->right);
        if(lh==0 && rh ==0)
        {
            return 1;
        }
        if(lh ==0)
        {
            return rh+1;
        }
        else if(rh == 0)
        {
            return lh+1;
        }
        else
        return min(lh,rh)+1;
        
    }
};