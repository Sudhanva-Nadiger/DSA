class Solution {
public:
    vector<int> getRow(int n){
        if(n==0){
            return {1};
        }
        vector<int> temp = {1};
        
        for(int i = 1;i<=n;++i){
            vector<int> x;
            x.emplace_back(1);
            for(int j = 0;j<temp.size()-1;++j){
                int p = temp[j]+temp[j+1];
                x.emplace_back(p);
            }
            
            x.emplace_back(1);
            temp = x;
        }
        
        return temp;
        
    }
};