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
    unordered_map<int, TreeNode*> par;
    TreeNode* startNode = NULL;
    void f(TreeNode* root, int start) {
        if(!root) return;
        
        if(root->val == start) {
            startNode = root;
        }
        
        if(root->left) {
            par[root->left->val] = root;
            f(root->left, start);
        }
        
        if(root->right) {
            par[root->right->val] = root;
            f(root->right, start);
        }
    }
    
    int amountOfTime(TreeNode* root, int start) {
        f(root, start);
        unordered_set<int> visited;
        queue<TreeNode*> q;
        q.push(startNode);
        visited.insert(start);
        int time = 0;
        while(q.size()) {
            int k = q.size();
            
            while(k--) {
                TreeNode* node = q.front();
                q.pop();
                
                if(node->left && !visited.count(node->left->val)) {
                    q.push(node->left);
                    visited.insert(node->left->val);
                }
                
                if(node->right && !visited.count(node->right->val)) {
                    q.push(node->right);
                    visited.insert(node->right->val);
                }
                
                TreeNode* p = par[node->val];
                if(p && !visited.count(p->val)) {
                    q.push(p);
                    visited.insert(p->val);
                }
            }
            
            if(q.size()) {
                time++;
            }
        }
        return time;
    }
};