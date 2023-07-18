class TrieNode {
    public:
        vector<TrieNode*> children;
        bool flag;
        TrieNode() {
            children.resize(26, NULL);
            flag = false;
        }
};

class Trie {
    TrieNode* root = NULL;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string& word) {
        TrieNode* t = root;
        
        for(int i = 0; i < word.size(); i++) {
            int id = word[i]-'a';
            TrieNode* child;
            if(t->children[id] == NULL) {
                child = new TrieNode();
                t->children[id] = child;
            }else {
                child = t->children[id];
            }
            
            t = child;
        }
        
        t->flag = true;
    }
    
    string getPref(string& word) {
        TrieNode* t = root;
        
        for(int i = 0; i < word.size(); i++) {
            int id = word[i]-'a';
            
            if(t && t->flag) return word.substr(0, i);
            
            if(!t->children[id]) {   
                return word;
            }
            
            t = t->children[id];
        }
        
        return word;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie* t = new Trie();
        for(auto it : dictionary) t->insert(it);
        
        stringstream ss(sentence);
        string word;
        string ans = "";
        
        while(!ss.eof()) {
            getline(ss, word, ' ');
            ans.append(t->getPref(word) + " ");
        }
        
        ans.pop_back();
        return ans;
    }
};