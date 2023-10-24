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
    void solve(TreeNode* root,int count,unordered_map<int,int>& mp){
        if(!root){
            return;
        }
        
        if(mp.find(count) == mp.end()){
            mp[count] = root->val;
        }
        else{
            mp[count] = max(mp[count],root->val);
        }
        
        solve(root->left,count+1,mp);
        solve(root->right,count+1,mp);
        
        return;
        
    }
    vector<int> largestValues(TreeNode* root) {
        unordered_map<int,int> mp;
        solve(root,0,mp);
        vector<int> ans;
        for(int i = 0;i<=1e4;i++){
            if(mp.find(i) == mp.end()){
                break;
            }
            ans.push_back(mp[i]);
        }
        
        return ans;
    }
};