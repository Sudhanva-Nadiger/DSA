class Solution {
public:
    string rankTeams(vector<string>& votes) {
        unordered_map<char, unordered_map<int, int>> mp;
        
        for(auto it: votes) {
            for(int i = 0; i < it.size(); i++) {
                mp[it[i]][i+1]++;
            }
        }
        
        string s = votes[0];
        sort(s.begin(), s.end(), [&mp, &s](char a, char b) {
            auto r1 = mp[a];
            auto r2 = mp[b];
            
            for(int rank = 1; rank <= s.size(); rank++) {
                if(r1[rank] > r2[rank]) {
                    return true;
                }else if(r1[rank] < r2[rank]) {
                    return false;
                }
            }
            return a < b;
        });
        return s;
    }
};