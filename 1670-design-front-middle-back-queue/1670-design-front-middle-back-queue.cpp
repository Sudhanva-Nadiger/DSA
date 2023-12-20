class FrontMiddleBackQueue {
    vector<int> arr;
public:
    FrontMiddleBackQueue() {
        arr.clear();
    }
    
    bool isEmpty() {
        return !arr.size();
    }
    
    void pushFront(int val) {
        arr.insert(arr.begin(), val);
        return;
    }
    
    void pushMiddle(int val) {
        int mid = arr.size()/2;
        arr.insert(arr.begin()+mid, val);
        return;
    }
    
    void pushBack(int val) {
        arr.push_back(val);
    }
    
    int popFront() {
        if(isEmpty()) return -1;
        
        int front = arr[0];
        arr.erase(arr.begin());
        return front;
    }
    
    int popMiddle() {
        if(isEmpty()) return -1;
        int n = arr.size();
        int mid = (n-1)/2;
        
        int middle = arr[mid];

        arr.erase(arr.begin()+mid);
        return middle;
    }
    
    int popBack() {
        if(isEmpty()) return -1;
        
        int back = arr.back();
        arr.pop_back();
        return back;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */