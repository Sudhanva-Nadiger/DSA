class DSU {
  public:
    vector<int> parent, size;
    
    DSU(int n)  {
        parent.resize(n+1, 0);
        size.resize(n+1, 1);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int findPar(int x) {
        if(x == parent[x]) return x;
        
        return parent[x] = findPar(parent[x]);
    }
    
    void unionBySize(int u,int v) {
        u = findPar(u);
        v = findPar(v);
        if(u == v) return;
        
        if(size[u] > size[v]) {
            parent[v] = u;
            size[u] += size[v];
        }else {
            parent[u] = v;
            size[v] += u;
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        DSU ds(n);
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    ds.unionBySize(i, j);
                }
            }
        }
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(i == ds.parent[i]) {
                count++;
            }
        }
        return n-count;
    }
};