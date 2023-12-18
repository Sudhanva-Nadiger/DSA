class Solution {
public:
    string ans = "";
    void f(int n, int& k, int prev, string s = "") {
        if(n == 0) {
            k--;
            
            if(k == 0) {
                ans = s;
            }
            
            return;
        }
        
        for(char c = 'a'; c <= 'c'; c++) {
            int curr = c - 'a';
            if(prev != curr) {
                s.push_back(c);
                f(n-1, k, curr, s);
                s.pop_back();
            }
        }
        
    }
    
    string getHappyString(int n, int k) {
        f(n, k, -1);
        return ans;
    }
};