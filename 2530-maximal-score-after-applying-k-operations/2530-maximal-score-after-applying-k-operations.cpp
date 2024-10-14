class Solution {
public:
    #define ll long long
    
    long long maxKelements(vector<int>& nums, int k) {
        ll ans = 0ll;
        priority_queue<ll> pq(nums.begin(), nums.end());
        
        while(k--) {
            ll top = pq.top();
            pq.pop();
            
            ans += top;
            
            pq.push(ceil((double)top/3.0));
        }
        
        return ans;
    }
};