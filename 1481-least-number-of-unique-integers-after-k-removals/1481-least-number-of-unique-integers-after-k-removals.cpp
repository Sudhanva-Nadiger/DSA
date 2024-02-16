class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int, int> mp;
        for(auto it : arr) {
            mp[it]++;
        }
        
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto it : mp) {
            pq.push(it.second);
        }
        
        while(pq.size() && pq.top() <= k) {
            k -= pq.top();
            pq.pop();
        }
        
        return pq.size();
    }
};