class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length()-1;
        while(s[n]==' ')
        {
            s.pop_back();
            n--;
        }
        int i =s.length()-1;
        for(i;i>=0;i--)
        {
            if(s[i]==' ')
            {
                break;
            }
        }
        
        return s.length()-1 -i;
        
    }
};