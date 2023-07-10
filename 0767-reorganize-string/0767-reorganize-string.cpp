class Solution {
public:
    using pi = pair<int,int>;
    string reorganizeString(string s) {
       vector<int> arr(26);
        for(auto it : s) {
            arr[it-'a']++;
        }
        priority_queue<pi> pq;
        
        for(int i = 0; i < 26; i++) {
            if(arr[i]) {
                pq.push({arr[i], i});
            }
        }
        
        string ans = "";
        
        queue<pair<int, pi>> q;
        int time = 0;
        while(pq.size() || q.size()) {
            time += 1;
            if(pq.size()) {
                auto t = pq.top();
                pq.pop();

                if(ans.back() == (t.second+'a')) return "";
                ans.push_back((t.second+'a'));
                t.first--;

                if(t.first > 0)
                    q.push({time+1, t});
            }
            
            if(q.size() && q.front().first == time) {
                pq.push(q.front().second);
                q.pop();
            }
        }
        
        return ans;
    }
};