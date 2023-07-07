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
    vector<TreeNode*> f(int left, int right) {
        if(left > right) {
            return {NULL};
        }
        
        vector<TreeNode*> ans;
        
        for(int i = left; i <= right; i++) {
            auto l = f(left, i-1);
            auto r = f(i+1, right);
            
            for(auto it : l) {
                for(auto e : r) {
                    TreeNode* root = new TreeNode(i);
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
    vector<TreeNode*> generateTrees(int n) {
        return f(1, n);
    }
};