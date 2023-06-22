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
    vector<TreeNode*> f(int n) {
        if(n == 1) {
            return {new TreeNode(0)};
        }
        
        vector<TreeNode*> ans;
        
        for(int i = 2; i < n; i+=2) {
            auto l = f(i-1);
            auto r = f(n-i);
            
            for(auto it : l) {
                for(auto e : r) {
                    TreeNode* root = new TreeNode(0);
                    root->left = it;
                    root->right = e;
                    ans.push_back(root);
                }
            }
        }
        
        if(ans.size() == 0) {
            ans.push_back(NULL);
        }
        
        return ans;
    }
    
    
    vector<TreeNode*> allPossibleFBT(int n) {
        
        if(n%2 == 0) {
            return {};
        }
        
        return f(n);
    }
};