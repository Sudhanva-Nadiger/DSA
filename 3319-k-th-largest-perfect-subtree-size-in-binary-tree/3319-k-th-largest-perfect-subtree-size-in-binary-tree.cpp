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
    vector<int> arr;
    
    array<int, 3> f(TreeNode* root) {
        if(!root) return {0, 0, true};
        
        auto [lh, ls, lFlag] = f(root->left);
        auto [rh, rs, rFlag] = f(root->right);
        
        bool flag = true;
        
        if(lh == rh && lFlag && rFlag) {
            arr.push_back(ls+rs+1);
        } else {
            flag = false;
        }
        
        return {max(lh, rh)+1, ls+rs+1, lFlag && rFlag && flag};
    }
    
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        f(root);
        sort(arr.rbegin(), arr.rend());
        if(arr.size() < k) return -1;
        // for(auto it : arr) cout << it << endl;
        return arr[k-1];
    }
};