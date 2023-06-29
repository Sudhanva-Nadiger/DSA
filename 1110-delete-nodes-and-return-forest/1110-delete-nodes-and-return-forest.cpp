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
    unordered_set<int> st;
    vector<TreeNode*> ans;
    TreeNode* f(TreeNode* root) {
        if(!root) {
            return NULL;
        }
        
        root->left = f(root->left);
        root->right = f(root->right);
        
        if(st.find(root->val) != st.end()) {
            if(root->left)
                ans.push_back(root->left);
            if(root->right)
                ans.push_back(root->right);
            
            return NULL;
        }
        
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(auto it : to_delete) {
            st.insert(it);
        }
        
        auto t = f(root);
        if(t != NULL) ans.push_back(t);
        return ans;
    }
};