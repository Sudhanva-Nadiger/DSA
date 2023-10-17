class Solution {
public:
    static const int maxN = 1e4;
    int par[maxN+1], size[maxN+1];
    
    int findPar(int x) {
        if(par[x] == x) {
            return x;
        }
        
        return par[x] = findPar(par[x]);
    }
    
    bool unionMerge(int u, int v) {
        u = findPar(u);
        v  = findPar(v);
        
        if(v == u) {
            return false;
        }
        
        if(v > u) swap(u, v);
        
        size[u] += size[v];
        par[v] = u;
        
        return true;
    }
    
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int indegree[n+1];
        for(int i = 0; i <= n; i++) {
            size[i] = 1;
            par[i] = i;
            indegree[i] = 0;
        }
        
        for(int i = 0; i < n; i++) {
            if(leftChild[i] != -1 && !unionMerge(i, leftChild[i])) {
                return false;
            }
            
            if(leftChild[i] != -1) {
                indegree[leftChild[i]]++;
            }
            
            if(rightChild[i] != -1 && !unionMerge(i, rightChild[i])) {
                return false;
            }
            
            if(rightChild[i] != -1) {
                indegree[rightChild[i]]++;
            }
        }
        
        int ult = findPar(0);
        if(indegree[0] > 1) return false;
        for(int i = 1; i < n; i++) {
            if(findPar(i) != ult || indegree[i] > 1) return false;
        }
         
        return true;
    }
};