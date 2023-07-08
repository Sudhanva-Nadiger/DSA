class Solution {
public:
    string f(string& s, int& i) {
        int n = s.size();
        int num = 0;
        string temp = "";
        
        for(; i < n; i++) {
            if(isdigit(s[i])) {
                num = num*10 + (s[i]-'0');
            }
            
            if(s[i] >= 'a' && s[i] <= 'z') {
                temp.push_back(s[i]);
            }
            
            if(s[i] == '[') {
                auto x = f(s, ++i);
                string t = "";
                while(num-->0) {
                    t += x;
                }
                
                temp += t;
                num = 0;
            }else if(s[i] == ']') {
                return temp;
            }
        }
        
        return temp;
    }
    string decodeString(string s) {
        int i = 0;
        return f(s, i);
    }
};