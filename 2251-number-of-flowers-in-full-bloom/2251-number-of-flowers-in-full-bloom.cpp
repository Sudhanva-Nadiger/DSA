class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int, int> mp;
        for(auto it : flowers) {
            mp[it[0]] += 1;
            mp[it[1]+1] += -1;
        }
        
        vector<pair<int, int>> arr;
        for(auto it : mp) {
            arr.push_back(it);
            if(arr.size()>1) {
                arr[arr.size()-1].second += arr[arr.size()-2].second;
            }
        }
        
        vector<int> res;
        
        for(auto it : people) {
            int ans = -1;
            int l = 0, r = arr.size()-1;
            
            while(l <= r) {
                int mid = (l+r)/2;
                
                if(arr[mid].first > it) {
                    r = mid-1;
                } else {
                    ans = mid;
                    l = mid+1;
                }
            }
            
            res.push_back((ans != -1 ? (arr[ans].second >= 0 ? arr[ans].second : 0) : 0));
        }
        
        return res;
    }
    
};