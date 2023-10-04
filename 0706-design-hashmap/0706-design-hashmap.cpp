class MyHashMap {
public:
    vector<int>v;
    int size;
    MyHashMap() {
        size=1e6+1;
        v.resize(size);
        fill(v.begin(),v.end(),-1);
    }

    void put(int key, int value) {
        v[key]=value;
    }

    int get(int key) {
        return v[key];
    }

    void remove(int key) {
        v[key]=-1;
    }
};