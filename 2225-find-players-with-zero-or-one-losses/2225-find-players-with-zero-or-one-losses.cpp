class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& m) {
        map<int,int> lost;
        vector<vector<int>> ans;
        for(int i =0;i<m.size();i++)
        {
            lost[m[i][1]]++;
        }
        set<int> temp;
        for(int i = 0;i<m.size();i++)
        {
            if(lost[m[i][0]] == 0)
            {
                temp.insert(m[i][0]);
            }
        }
        vector<int> v(temp.begin(),temp.end());
        ans.push_back(v);
        set<int> t;
        for(int i = 0;i<m.size();i++)
        {
            if(lost[m[i][1]] == 1)
            {
                t.insert(m[i][1]);
            }
        }
        vector<int> x(t.begin(),t.end());
        ans.push_back(x);
        
        return ans;
    }
};