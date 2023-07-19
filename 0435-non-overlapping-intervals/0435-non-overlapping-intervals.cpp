class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals));
        
        int n = intervals.size();
        int e = intervals[0][1];
        int c = 0;
        
        for(int i = 1; i < n; i++) {
            if(e <= intervals[i][0]) {
                e = intervals[i][1];
            }else {
                e = min(e, intervals[i][1]);
                c++;
            }
        }
        
        return c;
    }
};