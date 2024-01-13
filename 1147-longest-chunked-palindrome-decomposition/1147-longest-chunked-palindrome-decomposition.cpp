class Solution {
public:
    pair<int, int> f(string& s, int i, int j) {
        if(i == j) return {1, s.size()};
        if(i > j) return {0, s.size()};
        
         int n = j-i+1;
         for(int k = 1; k <= n/2; k++) {
             
             string l = s.substr(i, k);
             string r = s.substr(j, k);
             
             // cout << l << "  " << r << endl;
             
             if(l == r) {
                 
                 return {2, i+k};
             }
             
             j--;
         }
        
        return {1, s.size()};
    }
    
    int longestDecomposition(string text) {
        int k = 0;
        int n = text.size();
        
        for(int i = 0; i < (n+1)/2;) {
            int j = n-i-1;
            auto t = f(text, i, j);
            k += t.first;
            i = t.second;
        }
        
        return k;
    }
};