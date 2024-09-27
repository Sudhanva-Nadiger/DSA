class MyCalendarTwo {
public:
    map<int, int> st;
    MyCalendarTwo() {
        st.clear();
    }
    
    bool book(int start, int end) {
        st[start] += 1;
        st[end] -= 1;
        
        int count = 0;
        
        for(auto it : st) {
            count += it.second;
            
            if(count >= 3) {
                break;
            }
        }
        
        if(count >= 3) {
            st[start] -= 1;
            st[end] += 1;
            return false;
        }
        
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */