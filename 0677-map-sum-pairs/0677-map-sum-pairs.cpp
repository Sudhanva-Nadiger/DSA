class TrieNode {
    public:
    TrieNode* children[26];
    int val;
    
    TrieNode() {
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        
        val = 0;
    }
    
    TrieNode(int v) {
        val = v;
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
    
};

class Trie {
TrieNode* root = NULL;
unordered_map<string, int> inserted;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insertWord(string& word, int val) {
        TrieNode* ptr = root;
        
        bool flag = false;
        if(inserted.count(word)) {
            flag = true;
        }
        
        for(int i = 0; i < word.size(); i++) {
            int id = word[i]-'a';
            if(ptr->children[id] == NULL) {
                ptr->children[id] = new TrieNode(val);
            } else {
                ptr->children[id]->val += val;
                if(flag) {
                    ptr->children[id]->val -= inserted[word];
                }
            }
            
            ptr = ptr->children[id];
        }
        
        inserted[word] = val;
    }
    
    int getSum(string& word) {
        TrieNode* ptr = root;
        
        for(int i = 0; i < word.size(); i++) {
            int id = word[i]-'a';
            if(ptr->children[id] == NULL) {
                return 0;
            } else {
                ptr = ptr->children[id];
            }
        }
        
        return ptr->val;
    }
};

class MapSum {
    Trie* t = NULL;
public:
    MapSum() {
        t = new Trie();
    }
    
    void insert(string key, int val) {
        t->insertWord(key, val);
    }
    
    int sum(string prefix) {
        return t->getSum(prefix);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */