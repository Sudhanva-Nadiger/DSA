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
    int countSwaps(vector<int>& nums) {
        vector<pair<int, int>> arr;
        
        for(int i = 0; i < nums.size(); i++) {
            arr.push_back({nums[i], i});
        }
        
        sort(begin(arr), end(arr));
        
        int minSwaps = 0;
        
        vector<int> visited(nums.size());
        
        for(int i = 0; i < nums.size(); i++) {
            if(visited[i] || arr[i].second == i) {
                continue;
            }
            
            int cycleSize = 0;
            int j = i;
            
            while(!visited[j]) {
                visited[j] = 1;
                cycleSize++;
                j = arr[j].second;
            }
            
            minSwaps += max(0, cycleSize-1);
        }
        
        return minSwaps;
    }
    
    int minimumOperations(TreeNode* root) {
        if(!root) return 0;
        
        int ans=0;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.size()) {
            int k = q.size();
            
            vector<int>level;
            for(int i = 0; i < k;i++) {
                auto front = q.front();
                q.pop();
                
                level.push_back(front->val);
                
                if(front->left) {
                    q.push(front->left);
                }
                
                if(front->right) {
                    q.push(front->right);
                }
            }
            
            ans += countSwaps(level);
        }
        
        return ans;
    }
};