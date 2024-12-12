class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        #define ll long long
        
        
        ll ans = 0;
        
        priority_queue<ll> pq(gifts.begin(), gifts.end());
        
        while(k--) {
            ll top = pq.top();
            pq.pop();
            
            top = sqrt(top);
            
            pq.push(top);
        }
        
        while(pq.size()) {
            ans += pq.top();
            pq.pop();
        }
        
        return ans;
    }
};