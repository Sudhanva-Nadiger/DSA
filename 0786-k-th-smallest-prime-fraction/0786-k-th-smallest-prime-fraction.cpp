class Solution {
    
    using doub = double;
    using pdd = pair<double, pair<int, int>>;
    
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        doub n = arr.size();
        priority_queue<pdd> pq;
        
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                doub fract = (double)arr[i]/(double)arr[j];
                
                if(pq.size() < k) {
                    pq.push({fract, {arr[i],arr[j]}});
                } else if(pq.top().first > fract) {
                    pq.pop();
                    pq.push({fract, {arr[i],arr[j]}});
                }
            }
        }
        
        auto [a, b] = pq.top().second;
        
        return {a, b};
    }
};