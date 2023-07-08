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
    void f(TreeNode* root, TreeNode* &prev,TreeNode* &first, TreeNode* &mid, TreeNode* &last) {
        if(!root) {
            return;
        }
        
        f(root->left, prev, first, mid, last);
        
        if(prev && prev->val >= root->val) {
            if(!first) {
                first = prev;
                mid = root;
            }else {
                last = root;
            }
        }
        
        prev = root;
        f(root->right, prev, first, mid, last);
    }
    
    void swap(TreeNode* &a, TreeNode* &b) {
        int t = a->val;
        a->val = b->val;
        b->val = t;
    }
    void recoverTree(TreeNode* root) {
        TreeNode *first = NULL, *last = NULL, *mid = NULL, *prev = NULL;
        f(root, prev, first, mid, last);
        if(!last) {
            swap(first, mid);
        }else {
            swap(first, last);
        }
    }
};