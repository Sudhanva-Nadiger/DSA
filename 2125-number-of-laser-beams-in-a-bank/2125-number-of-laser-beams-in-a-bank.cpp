class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0, prev = 0;
        for(string& s : bank) {
            int c = 0;
            for(char ch : s) {
                c += (ch == '1');
            }
            
            ans += (prev*c);
            
            if(c) prev = c;
        }
        
        return ans;
    }
};