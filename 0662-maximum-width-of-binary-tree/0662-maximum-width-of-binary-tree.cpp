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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0ll});
        int ans = 1;
        
        while(q.size()) {
            int k = q.size();
            int firstIndex = 0, lastIndex = 0;
            int minIndex = q.front().second;
            for(int i = 0; i < k; i++) {
                auto [node, index] = q.front();
                q.pop();
                
                index -= minIndex;
                if(i == 0) {
                    firstIndex = index;
                }
                
                if(i == k-1) {
                    lastIndex = index;
                }
                
                if(node->left) {
                    q.push({node->left, (long long)2ll*index+1ll});
                }
                if(node->right) {
                    q.push({node->right, (long long)2ll*index+2ll});
                }
            }
            
            ans = max(ans, lastIndex-firstIndex+1);
        }
        return ans;
    }
};