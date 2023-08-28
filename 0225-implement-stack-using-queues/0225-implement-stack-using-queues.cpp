class MyStack {
public:
    queue<int>mainQueue,tempQueue;
            MyStack()
            {
            }

            void push(int x)
            {
               while(!mainQueue.empty()){
            tempQueue.push(mainQueue.front());
            mainQueue.pop();
        }
        mainQueue.push(x);
        while(!tempQueue.empty()){
            mainQueue.push(tempQueue.front());
            tempQueue.pop();
        }
            }

            int top()
            {
                return mainQueue.front();
            }

            int pop()
            {
                int x = mainQueue.front();
                mainQueue.pop();
                return x;
            }

            bool empty()
            {
               if(mainQueue.empty())
               {
                   return true;
               }
               else{
                   return false;
               }
            }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */