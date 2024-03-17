class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& v) {
       vector<vector<int>> ans;
        for(auto& it : intervals){
            if(it[1] < v[0]){
                ans.emplace_back(it);
            }
            else if(it[0]>v[1]){
                ans.emplace_back(v);
                v[0] = it[0];
                v[1] = it[1];
            }
            else{
                v[0] = min(v[0],it[0]);
                v[1] = max(v[1],it[1]);
            }
        }
        
        ans.emplace_back(v);
        
        return ans;
    }
};