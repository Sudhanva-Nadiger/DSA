class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> pq;
        int ans = -1e9;
        for(auto it : points) {
            while(pq.size() && it[0]-pq.top().second > k) {
                pq.pop();
            }
            if(pq.size()) {
                ans = max(ans, pq.top().first + it[0]+it[1]);
            }
            
            pq.push({it[1]-it[0], it[0]});
        }
        
        return ans;
    }
};