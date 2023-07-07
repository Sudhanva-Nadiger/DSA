class DisjointUnion {
    vector<int> size, parent;
    public:
        DisjointUnion(int n) {
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
            int uPar = findPar(u);
            int vPar = findPar(v);
            
            if(vPar == uPar) return;
            
            if(size[uPar] > size[vPar]) {
                parent[vPar] = uPar;
                size[uPar] += size[vPar];
            }else {
                parent[uPar] = vPar;
                size[vPar] += size[uPar];
            }
        }
};

class Solution {
    DisjointUnion* t = NULL;
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        t = new DisjointUnion(1000);
        for(auto it : edges) {
            int u = it[0];
            int v = it[1];
            
            if(t->findPar(u) != t->findPar(v)) {
                t->unionBySize(u, v);
            }else {
                return it;
            }
        }
        
        return {};
    }
};