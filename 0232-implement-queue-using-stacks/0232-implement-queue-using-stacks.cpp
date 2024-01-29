class MyQueue {
    stack<int> mainStack, secondaryStack;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        while(mainStack.size()){
            secondaryStack.push(mainStack.top());
            mainStack.pop();
        }
        
        mainStack.push(x);
        
        while(secondaryStack.size()){
            mainStack.push(secondaryStack.top());
            secondaryStack.pop();
        }
        
        return ;
    }
    
    int pop() {
        if(empty()){
            return -1;
        }
        
        int x = mainStack.top();
        mainStack.pop();
        
        return x;
    }
    
    int peek() {
        if(empty()){
            return -1;
        }
        
        return mainStack.top();
    }
    
    bool empty() {
        return mainStack.size() == 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */