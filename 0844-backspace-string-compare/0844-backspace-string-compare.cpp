class Solution {
public:
    
    bool backspaceCompare(string s, string t) {
        int x = 0;
        
        for(int i = 0;i<s.size();++i){
            if(s[i] == '#'){
                x--;
                x = max(0,x);
            }
            else{
                s[x] = s[i];
                ++x;
            }
        }
        
        int y = 0;
        
        for(int i = 0;i<t.size();++i){
            if(t[i] == '#'){
                y--;
                y = max(0,y);
            }
            else{
                t[y] = t[i];
                ++y;
            }
        }
        
        if(x != y){
            return false;
        }
        
        return s.substr(0,x) == t.substr(0,y);
    }
};