class CustomStack {
    vector<int> stack;
    int top;
public:
    CustomStack(int maxSize) {
        stack.resize(maxSize, -1);
        top = -1;
    }
    
    void push(int x) {
        if(top+1 < stack.size()) {
            stack[++top] = x;
        }
    }
    
    int pop() {
        if(top < 0) return -1;
        
        int popped = stack[top--];
        
        return popped;
    }
    
    void increment(int k, int val) {
        for(int i = 0; i < k && i < stack.size(); i++) {
            stack[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */