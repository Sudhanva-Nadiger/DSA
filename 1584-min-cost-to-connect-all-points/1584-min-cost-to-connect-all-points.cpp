class Solution {
public:
    const static int maxN = 20001;
    int par[maxN], size[maxN];
    
    int findPar(int x) {
        if(par[x] == x) {
            return x;
        }
        
        return par[x] = findPar(par[x]);
    }
    
    bool merge(int u, int v) {
        u = findPar(u);
        v = findPar(v);
        
        if(u == v) return false;
        
        if(size[u] < size[v]) swap(u, v);
        
        size[u] += size[v];
        par[v] = u;
        
        return true;
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        vector<pair<int, pair<int, int>>> arr;
        for(int i = 0; i < n; i++) {
            par[i] = i;
            size[i] = 1;
            for(int j = i+1; j < n; j++) {
                int dist = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                arr.push_back({dist, {i, j}});
            }
        }
        
        sort(arr.begin(), arr.end());
        int ans = 0;
        for(auto it : arr) {
            if(merge(it.second.first, it.second.second)) {
                ans += it.first;
            }
        }
        
        return ans;
    }
};