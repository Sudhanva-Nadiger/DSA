class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> mp;
        for(char c : s){
            mp[c]++;
        }
        
        for(char c : t){
           mp[c]++;
        }
        
        for(auto it : mp){
            if(it.second&1){
                return it.first;
            }
        }
        
        return 'a';
    }
};