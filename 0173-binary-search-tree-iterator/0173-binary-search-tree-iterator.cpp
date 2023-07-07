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
class BSTIterator {
    int i;
    vector<int> nums;
public:
    void f(TreeNode* root){
        if(!root) return;
        
        f(root->left);
        nums.push_back(root->val);
        f(root->right);
    }
    
    BSTIterator(TreeNode* root) {
        f(root);
        i = 0;
    }
    
    int next() {
        return nums[i++];
    }
    
    bool hasNext() {
        return i < nums.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */