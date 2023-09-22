class Solution {
public:
    bool isSubsequence(string s, string t) { 
            for(int  i =0;i<t.size();i++)
            {
                if(t[i] == s[0])
                {
                    s = s.substr(1);
                }
            }
        
        return s.size()==0;
    }
};