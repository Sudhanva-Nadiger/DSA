class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> ans;
        
        if(x == 1 && y == 1) {
            if(2 <= bound) ans.push_back(2);
            return ans;
        }
        
        if(x == 1 || y == 1) {
            y = max(x, y);
            x = 1;
            int t = y;
            
            if(2 <= bound) ans.push_back(2);
            
            while(y + 1 <= bound) {
                ans.push_back(y+1);
                y = y*t;
            }
            
            
            return ans;
        }
        
        vector<int> vis(bound+1);
        
        for(int i = 0; pow(x, i) <= bound; i++) {
            int a = pow(x, i);
            for(int j = 0; a + pow(y, j) <= bound; j++) {
                int b = a + pow(y, j);
                if(!vis[b]) {
                    ans.push_back(b);
                    vis[b] = 1;
                }
            }
        }
        
        return ans;
    }
};