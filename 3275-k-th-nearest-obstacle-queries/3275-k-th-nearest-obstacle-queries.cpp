class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        priority_queue<int> pq;
        vector<int> ans;
        for(auto it : queries) {
            int dist = abs(it[0]) + abs(it[1]);
            
            if(pq.size() < k) {
                pq.push(dist);
            } else if(pq.top() > dist) {
                pq.pop();
                pq.push(dist);
            }
            
            ans.push_back(pq.size() >= k ? pq.top() : -1);
        }
        
        return ans;
    }
};