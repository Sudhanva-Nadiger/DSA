class StockPrice {
    map<int, int> priceOfStockAt;
    map<int, int> mp;
    int latest;
public:
    StockPrice() {
        latest = 0;
    }
    
    void update(int timestamp, int price) {
        if(!priceOfStockAt.count(timestamp)) {
            mp[price]++;
        } else {
            int oldPrice = priceOfStockAt[timestamp];
            mp[oldPrice]--;
            mp[price]++;
            if(mp[oldPrice] <= 0) {
                mp.erase(oldPrice);
            }
        }
        
        priceOfStockAt[timestamp] = price;
    }
    
    int current() {
        return priceOfStockAt.rbegin()->second;;
    }
    
    int maximum() {
        return mp.rbegin()->first;
    }
    
    int minimum() {
        return mp.begin()->first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */