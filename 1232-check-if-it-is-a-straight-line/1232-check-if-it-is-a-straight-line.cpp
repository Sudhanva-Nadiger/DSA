class Solution {
public:
    float getSlope(vector<int>& a,vector<int>& b){
        if(a[0] == b[0]){
            return INT_MAX;
        }
        return ((float)(a[1]-b[1]))/(float)(a[0]-b[0]);
    }
    bool checkStraightLine(vector<vector<int>>& c) {
        int n = c.size();
        if(n == 2){
            return true;
        }
        
        float m = getSlope(c[0],c[1]);
        
        for(int i =2;i<n;i++){
            float m1 = getSlope(c[0],c[i]);
            cout<<m1<<endl;
            
            if(m1 != m){
                return false;
            }
        }
        
        return true;
    }
};