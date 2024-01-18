class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int ans = 0, prev = 0;
        for(int it : rungs) {
            int diff = it-prev;
            if(diff > dist) {
                ans += (diff-1)/dist;
            }
            
            prev = it;
        }
        
        return ans;
    }
};