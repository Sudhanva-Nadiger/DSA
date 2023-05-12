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
    unordered_map<TreeNode*, int> mp;
    unordered_map<TreeNode*,TreeNode*> par;
    
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(!root) return root;
        
        queue<TreeNode*> q;
        
        q.push(root);
        
        par[root] = NULL;
        
        while(q.size()) {
            int k = q.size();
            
            int rowSum = 0;
            
            vector<TreeNode*> arr;
            
            for(int i = 0; i < k; i++) {
                auto node = q.front();
                arr.push_back(node);
                q.pop();
                
                rowSum += node->val;
                
                if(node->left) {
                    q.push(node->left);
                    mp[node] = mp[node] + node->left->val;
                    par[node->left] = node;
                }
                
                if(node->right) {
                    q.push(node->right);
                    mp[node] = mp[node] + node->right->val;
                    par[node->right] = node;
                }
            }
            
            for(auto it: arr) {
                auto parent = par[it];
                int sameParSum = mp[parent];
                if(parent == NULL) {
                    sameParSum = it->val;
                }
                it->val = abs(rowSum - sameParSum);
            }
        }
        
        return root;
    }
};