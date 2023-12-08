class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> mp;
        for(auto it : arr) mp[it]++;
        
        if(mp[0]&1) return false;
        
        sort(arr.begin(), arr.end());
        
        int count = 0;
        for(auto it : arr) {
            if(mp[it] && mp[2*it]) {
                count++;
                mp[it]--;
                mp[2*it]--;
            }
        }
        
        return (count == (arr.size()/2));
    }
};