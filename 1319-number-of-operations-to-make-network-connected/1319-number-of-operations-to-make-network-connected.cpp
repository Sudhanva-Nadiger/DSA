class DSU {
    public:
        vector<int> size, parent;
        
        DSU(int n) {
            size.resize(n+1, 1);
            parent.resize(n+1, 0);
            
            for(int i = 0; i < parent.size(); i++) {
                parent[i] = i;
            }
        }
    
        int findPar(int x) {
            if(x == parent[x]) {
                return x;
            }
            
            return parent[x] = findPar(parent[x]);
        }
    
        void unionBySize(int u, int v) {
            int upar = findPar(u);
            int vpar = findPar(v);
            
            if(vpar == upar) return;
            
            if(size[upar] > size[vpar]) {
                parent[vpar] = upar;
                size[upar] += size[vpar];
            }else {
                parent[upar] = vpar;
                size[vpar] += size[upar];
            }
        }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int extraEdges = 0;
        DSU ds(n);
        for(auto it : connections) {
            if(ds.findPar(it[0]) != ds.findPar(it[1])) {
                ds.unionBySize(it[0], it[1]);
            }else {
                extraEdges++;
            }
        }
        
        int comp = 0;
        for(int i = 0; i < n; i++) {
            if(i == ds.parent[i]) {
                comp++;
            }
        }
        
        if(extraEdges >= comp-1) {
            return comp-1;
        }
        
        return -1;
    }
};