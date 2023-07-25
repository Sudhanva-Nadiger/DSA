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
class CBTInserter {
    TreeNode* root = NULL;
public:
    CBTInserter(TreeNode* root) {
        this->root = root;
    }
    
    int insert(int val) {
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.size()) {
            auto front = q.front();
            q.pop();
            
            if(!front->left) {
                front->left = new TreeNode(val);
                return front->val;
            }else {
                q.push(front->left);
            }
            
            if(!front->right) {
                front->right = new TreeNode(val);
                return front->val;
            }else {
                q.push(front->right);
            }
        }
        
        return -1;
    }
    
    TreeNode* get_root() {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */