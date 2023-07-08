/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "x,";
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    TreeNode* f(queue<string>& q) {
        if(!q.size()) return NULL;
        
        auto front = q.front();
        q.pop();
        
        if(front == "x") {
            return NULL;
        }
        
        TreeNode* root = new TreeNode(stoi(front));
        
        root->left = f(q);
        root->right = f(q);
        
        return root;
    }
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string word;
        queue<string> q;
        
        while(!ss.eof()) {
            getline(ss, word, ',');
            q.push(word);
        }
        
        return f(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));