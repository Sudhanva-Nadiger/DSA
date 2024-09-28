class MyCircularDeque {
    int *arr;
    int front;
    int rear;
    int size;
public:
    MyCircularDeque(int k) {
        size = k;
        front = rear = -1;
        arr = new int[size];
    }
    
    bool insertFront(int val) {
        if(isFull()){
            return false;
        }
        
        if(front == -1){
            front = 0;
            rear = 0;
            arr[0] = val;
        }
        else{
            if(front == 0){
                front = size-1;
            }
            else{
                front = front-1;
            }
            arr[front] = val;
        }
        
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()){
            return false;
        }
        
        if(rear == -1){
            rear = 0;
            front = 0;
            arr[0] = value;
        }
        else{
            rear = (rear+1)%size;
            arr[rear] = value;
        }
        
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()){
            return false;
        }
        
        if(front == rear){
            front = rear = -1;
        }
        else{
            front = (front+1)%size;
        }
        
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()){
            return false;
        }
        
        if(front == rear){
            front = rear = -1;
        }
        else{
            if(rear == 0){
                rear = size-1;
            }
            else{
                rear = rear-1;
            }
        }
        
        return true;
    }
    
    int getFront() {
        if(isEmpty()){
            return -1;
        }
        
        return arr[front];
    }
    
    int getRear() {
        if(isEmpty()){
            return -1;
        }
        
        return arr[rear];
    }
    
    bool isEmpty() {
        return (front == -1 and rear == -1);
    }
    
    bool isFull() {
        return (rear+1)%size == front;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */