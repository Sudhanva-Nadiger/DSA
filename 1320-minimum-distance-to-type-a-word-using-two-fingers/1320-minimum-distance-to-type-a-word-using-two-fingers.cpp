class Solution {
public:
    pair<int, int> getCoOrdinate(int index) {
        int row = index/6;
        int col = index%6;
        
        return {row, col};
    }
    
    int getDistance(int a, int b) {
        auto distA = getCoOrdinate(a);
        auto distB = getCoOrdinate(b);
        
        return abs(distA.first-distB.first) + abs(distA.second-distB.second);
    }
    
    int dp[301][28][28];
    
    int f(string& s, int i, int prevLeft, int prevRight) {
        if(i == s.size()) return 0;
        
        int& st = dp[i][prevLeft+1][prevRight+1];
        
        if(st != -1) return st;
        
        int useLeft = f(s, i+1, s[i]-'A', prevRight);
        int useRight = f(s, i+1, prevLeft, s[i]-'A');
        
        if(prevLeft != -1) {
            useLeft += getDistance(s[i]-'A', prevLeft);
        }
        
        if(prevRight != -1) {
            useRight += getDistance(s[i]-'A', prevRight);
        }
        
        return st = min(useLeft, useRight);
    }
    
    int minimumDistance(string word) {
        memset(dp, -1, sizeof dp);
        return f(word, 0, -1, -1);
    }
}; 