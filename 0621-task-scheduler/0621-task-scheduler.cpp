class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        for(auto it : tasks) {
            mp[it]++;
        }
        
        priority_queue<int> pq;
        
        for(auto it : mp) {
            pq.push(it.second);
        }
        
        queue<pair<int, int>> q;
        
        
        int time = 0;
        
        while(q.size() || pq.size()) {
            time += 1;
            
            if(pq.size()) {
                int top = pq.top()-1;
                pq.pop();
                
                if(top > 0) {
                    q.push({top, time+n});
                }
            }
            
            if(q.size() && q.front().second == time) {
                pq.push(q.front().first);
                q.pop();
            } 
        }
        
        return time;
    }
};