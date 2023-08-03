class Solution {
public:
    void solve(string s,map<int,string> &mp,string a,vector<string> &ans){
        if(s.length()==0){
            ans.push_back(a);
            return;
        }
        
        char c = s[0];
        string code = mp[c-'0'];
        string ros = s.substr(1);
        for(int i = 0;i<code.size();++i){
            solve(ros,mp,a+code[i],ans);
        }
        
        return ;
    }
    vector<string> letterCombinations(string digits) {
        
        map<int,string> mp;
        
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
        
        vector<string> ans ;
        if(digits == ""){
            return ans;
        }
        solve(digits,mp,"",ans);
        return ans;
        
    }
};