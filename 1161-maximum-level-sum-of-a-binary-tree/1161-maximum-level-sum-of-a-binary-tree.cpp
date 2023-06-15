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
    unordered_map<int, int> mp;
    int ans = INT_MIN;
    int minLevel = 1e9;
    
    void f(TreeNode* root, int level) {
        if(!root) return;
        
        mp[level] += root->val;
        
        
        f(root->left, level+1);
        f(root->right, level+1);
    }
    int maxLevelSum(TreeNode* root) {
        f(root, 1);
        
        for(auto it : mp) {
            int level = it.first;
            int sum = it.second;
            
            if(ans < sum) {
                ans = sum;
                minLevel = level;
            }else if(ans == sum) {
                minLevel = min(minLevel, level);
            }
        }
        
        return minLevel;
    }
};