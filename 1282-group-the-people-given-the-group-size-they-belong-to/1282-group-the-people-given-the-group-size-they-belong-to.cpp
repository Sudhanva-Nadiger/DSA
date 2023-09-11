class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        unordered_map<int,vector<int>> mp;
        
        for(int i = 0;i<n;++i){
            mp[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> ans;
        for(auto it : mp){
            int x = it.second.size();
            vector<int> temp;
            int i = 0;
            for(int i = 0;i<=x;i++){
                if(temp.size()==it.first){
                    ans.push_back(temp);
                    temp.clear();
                }
                if(i<x)
                    temp.push_back(it.second[i]);
            }
        }
        
        return ans;
        
    }
};