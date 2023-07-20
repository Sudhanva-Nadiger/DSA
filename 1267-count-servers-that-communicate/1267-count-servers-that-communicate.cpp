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
        if(x == par[x]) return x;
        return par[x] = findPar(par[x]);
    }
    
    void unionBySize(int u, int v) {
        u = findPar(u);
        v = findPar(v);
        
        if(u == v) {
            return;
        }
        
        if(size[u] > size[v]) {
            par[v] = u;
            size[u] += size[v];
        }else {
            par[u] = v;
            size[v] += size[u];
        }
    }
};

class Solution {
public:
    void f(vector<vector<int>>& map, DSU& d) {
        for(int i = 0; i < map.size(); i++) {
            int s = map[i].size();
            
            for(int j = 1; j < s; j++) {
                d.unionBySize(map[i][j], map[i][j-1]);
            }
            
        }
    }
    
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        DSU d(m*n);
        vector<vector<int>> rowMap(m), colMap(n);
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    int num = n*i + j;
                    // cout << "j: " << j << " " << num << endl;
                    rowMap[i].push_back(num);
                    colMap[j].push_back(num);
                }
            }
        }
                
        f(rowMap, d);
        f(colMap, d);
        
        int ans = 0;
        for(int i = 0; i < d.par.size(); i++) {
            int p = d.par[i];
            if(p == i && d.size[i] > 1) {
                ans += d.size[i];
            }
        }

        return ans;
    }
};