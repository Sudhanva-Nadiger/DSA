class Solution {
public:
    string removeKdigits(string num, int k) {
        deque<char> q;
        
        for(auto c: num) {
            while(q.size() && c < q.back() && k-- > 0) {
                q.pop_back();
            }
            
            q.push_back(c);
        }
        
        while(k-- > 0) {
            q.pop_back();
        }
        
        while(q.size() > 1 && q.front() == '0') {
            q.pop_front();
        }
        
        string res(q.begin(), q.end());
        
        if(res == "") res = "0";
        
        return res;
    }
};