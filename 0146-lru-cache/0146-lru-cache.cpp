class Node{
    public:
        int key;
        int value;
        Node *next;
        Node *prev;
        Node(int x,int y){
            key =x;
            value = y;
            prev = NULL;
            next = NULL;
        }
};

class LRUCache {
    Node* head = new Node(-100,-100);
    Node* tail = new Node(-100,-100);
    int cap;
    unordered_map<int,Node*> mp;
public:
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(Node *newnode){  //function that inserts a newnode right after head
    
    Node *temp=head->next;
    newnode->next=temp;
    newnode->prev=head;
    head->next=newnode;
    temp->prev=newnode;
}
    
    void deleteNode (Node *delnode){  //function that deletes node placed just before tail
    
    Node *delprev = delnode->prev;
    Node *delnext = delnode->next;
    delprev->next=delnext;
    delnext->prev=delprev;
}
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            Node* res = mp[key];
            int ans = res->value;
            
            
            deleteNode(res);
            mp.erase(key);
            addNode(res);
            mp[key] = head->next;
            
            
            return ans;
        }
        
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            deleteNode(mp[key]);
            mp.erase(key);
        }
        if(mp.size() == cap){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        
         addNode(new Node(key,value));
         mp[key] = head->next;
        
        //Node* x = head;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */