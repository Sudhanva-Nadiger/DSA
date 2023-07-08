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
    int preIndex = 0;
    int postIndex = 0;
    TreeNode* constructFromPrePost(vector<int>& a, vector<int>& b) {
        TreeNode* root = new TreeNode(a[preIndex++]);
        if(root->val != b[postIndex]){
            root->left = constructFromPrePost(a,b);
        }
        if(root->val != b[postIndex]){
            root->right = constructFromPrePost(a,b);
        }
        postIndex++;
        return root;
    }
};