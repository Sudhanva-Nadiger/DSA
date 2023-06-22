class Solution {
public:
    void f(string& s, unordered_map<int, vector<string>>& mp) {
        
        for(int i = 0; i < s.size(); i++) {
            string temp ="";
            for(int j = i; j < s.size();j++) {
                temp.push_back(s[j]);
                mp[temp.size()].push_back(temp);
            }
        }
        
        return ;
    }
    int countSubstrings(string s, string t) {
        unordered_map<int, vector<string>> mp1, mp2;
        f(s, mp1);
        f(t, mp2);
        
        int ans = 0;
        
        for(int count = 1; count <= s.size(); count++) {
            
            for(auto word1: mp1[count]) {
                // cout << word1 << " ";
                for(auto word2 : mp2[count]) {
                    // cout << word2 << endl;
                    int c = 0;
                    for(int index = 0; index < count; index++) {
                        if(word1[index] != word2[index]) {
                            c++;
                        }
                        
                        if(c > 1) {
                            break;
                        }
                    }
                    
                    if(c == 1) ans++;
                }
            }
            
        }
        
        return ans;
        
    }
};