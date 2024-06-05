class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> ans;
        map<char,int> mp;
        for(char c: words[0]){
            mp[c]++;
        }
         //map<char,int> ma;
        for(int i = 1;i<words.size();++i){
             map<char,int> ma;
            for(int j = 0;j<words[i].size();++j){
                ma[words[i][j]]++;
            }
            
            for(auto c : words[0]){
                    mp[c] = min(mp[c],ma[c]);
            }
        }
        for(auto it : mp){
            if(mp[it.first]){
                string x = "";
                    x += it.first;
                for(int i = 0;i<mp[it.first];++i){
                    ans.emplace_back(x);
                }
            }
        }
        
        return ans;
    }
};