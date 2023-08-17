class DSU {
    public:
        vector<int> par, size;
        DSU(int n) {
            par.resize(n+1, 0);
            size.resize(n+1, 1);
            
            for(int i = 0; i < par.size(); i++) {
                par[i] = i;
            }
        }
    
        int findPar(int x) {
            if(x == par[x]) {
                return x;
            }
            
            return par[x] = findPar(par[x]);
        }
    
        void unionBySize(int u, int v) {
            u = findPar(u);
            v = findPar(v);
            
            if(v == u) return;
            
            if(size[u] > size[v]) {
                par[v] = u;
                size[u] += size[v];
            } else {
                par[u] = v;
                size[v] += size[u];
            }
        }
};

class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        unordered_map<int, vector<int>> adj;
        int n = strs.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n;  j++) {
                
                if(i != j) {
                    int size = strs[i].size();
                    int count = 0;
                    int first = -1, second = -1;
                    
                    for(int index = 0; index < size; index++) {
                        if(strs[i][index] != strs[j][index]) {
                            count++;
                            if(first == -1) {
                                first = index;
                            }else {
                                second = index;
                            }
                        }
                    }
                    
                    if(count == 2) {
                        if(strs[i][first] == strs[j][second] && strs[i][second] == strs[j][first]) {
                            adj[i].push_back(j);
                        }
                    } else if(count == 0) {
                        adj[i].push_back(j);
                    }
                }
            }
        }
        
        DSU ds(n);
        
        for(int i = 0; i < n; i++) {
            for(auto it : adj[i]) {
                ds.unionBySize(i, it);
            }
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(ds.par[i] == i) {
                ans++;
            }
        }
        return ans;
    }
};