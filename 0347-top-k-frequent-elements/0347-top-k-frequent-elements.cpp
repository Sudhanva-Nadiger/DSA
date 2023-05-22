class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        
        unordered_map<int, int> mp;
        
        for(auto it : nums) {
            mp[it]++;
        }
        
        // freq, num;
        priority_queue<pair<int,int>> pq;
        
        for(auto it : mp) {
            int num = it.first;
            int frq = it.second;
            
            pq.push({frq, num});
        }
        
        while(k-- and pq.size()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};