class LUPrefix {
    int i = 0;
    set<int> st;
public:
    LUPrefix(int n) {
        
    }
    
    void upload(int video) {
        if(video == i+1) {
            i++;
        }else {
            st.insert(video);
        }
        
        while(st.size() and *(st.begin()) == i+1) {
            i++;
            st.erase(st.begin());
        }
    }
    
    int longest() {
        return i;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */