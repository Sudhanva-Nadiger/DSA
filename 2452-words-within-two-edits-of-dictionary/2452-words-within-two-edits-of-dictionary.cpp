class Solution {
public:
    bool canEdit(string& s, vector<string>& dict) {
        int n = s.size();
        
        for(auto& d: dict) {
            if(n != d.size()) {
                continue;
            }
            
            int count = 0;
            for(int i = 0; i < n && count <= 2; i++) {
                if(s[i] != d[i]) {
                    count++;
                }
            }
            
            if(count <= 2) return true;
        }
        
        return false;
    }
    
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dict) {
        vector<string> ans;
        
        for(string& s : queries) {
            if(canEdit(s, dict)) {
                ans.push_back(s);
            }
        }
        
        return ans;
    }
};