class Solution {
public:
    
    static int hammingWeight(int n){
        int ans = 0;
        while(n){
            ans += (n&1);
            
            n/=2;
        }
        
        return ans;
    }
    
    static bool compare(int& a,int& b){
        int x = hammingWeight(a);
        int y = hammingWeight(b);
        if(x == y){
            return a<=b;
        }
        
        return x<y;
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),compare);
        return arr;
    }
};