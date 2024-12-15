class Solution {
public:
    double profit(double pass, double tot) {
        return (pass+1)/(tot+1) - pass/tot;
    }
    
    double maxAverageRatio(vector<vector<int>>& classes, int extra) {
        priority_queue<pair<double,int>> pq;
        auto n = classes.size();
        
        for(int i = 0; i < n; i++) {
            int pass = classes[i][0], total = classes[i][1];
            pq.push({profit(pass, total), i});
        }
        
        while(extra--) {
            auto [prof, i] = pq.top();
            pq.pop();
            
            int& pass = classes[i][0];
            int& total = classes[i][1];
            
            pass += 1;
            total += 1;
            
            pq.push({profit(pass, total), i});
        }
        
        double ans = 0;
        for(auto it : classes) {
            ans += (double)(double)it[0]/(double)it[1];
        }
        
        return ans/n;
        
    }
};