/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void add(unordered_map<int, vector<int>>& adj, int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void f(unordered_map<int, vector<int>>& adj, TreeNode* root) {
        if(!root) {
            return;
        }
        
        int u = root->val;
        if(root->left) {
            int v = root->left->val;
            add(adj, u, v);
        }
        
        if(root->right) {
            int v = root->right->val;
            add(adj, u, v);
        }
        
        f(adj, root->left);
        f(adj, root->right);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int, vector<int>> adj;
        f(adj, root);
        queue<pair<int, pair<int, int>>> q;
        q.push({target->val, {-1, k}});
        vector<int> ans;
        
        while(q.size()) {
            auto t = q.front();
            q.pop();
            
            int node = t.first;
            int par = t.second.first;
            int dist = t.second.second;
            
            if(dist == 0) {
                ans.push_back(node);
                continue;
            }
            
            for(auto it : adj[node]) {
                if(it != par) {
                    q.push({it, {node, dist-1}});
                }
            }
        }
        
        return ans;
    }
};