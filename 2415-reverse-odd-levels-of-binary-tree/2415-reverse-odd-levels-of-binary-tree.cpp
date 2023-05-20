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
    TreeNode* reverseOddLevels(TreeNode* root) {
        int level = 0;
        queue<TreeNode*> q;
        q.push(root);
        
        
        while(q.size()) {
            int k = q.size();
           
            vector<TreeNode*> oddLevelNodes;
            bool canPush = (level%2 == 0);
            
            for(int i = 0; i < k; i++) {
                TreeNode* curr = q.front();
                q.pop();
                
                if(curr->left) {
                    q.push(curr->left);
                    if(canPush) {
                        oddLevelNodes.push_back(curr->left);
                    }
                }
                
                if(curr->right) {
                    q.push(curr->right);
                    if(canPush) {
                        oddLevelNodes.push_back(curr->right);
                    }
                }
            }
            
            if(canPush) {
               
                for(int  j = 0; j < oddLevelNodes.size()/2; j++) {

                    cout << oddLevelNodes[j]->val<< endl;
                    cout << oddLevelNodes[oddLevelNodes.size()-j-1]->val<< endl;
                    auto left = oddLevelNodes[j];
                    auto right = oddLevelNodes[oddLevelNodes.size()-j-1];

                    int temp = left->val;
                    left->val = right->val;
                    right->val = temp;
                }
            }
            
            oddLevelNodes.clear();
            level++;
        }
        
        return root;
    }
};