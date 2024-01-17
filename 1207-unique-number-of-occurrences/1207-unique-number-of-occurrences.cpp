class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> mp;
        for(auto it : arr) mp[it]++;
        set<int> st;
        for(auto [a, f] : mp) st.insert(f);
        return st.size() == mp.size();
    }
};