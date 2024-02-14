class Solution {
public:
    vector<int> rearrangeArray(vector<int>& arr) {
        vector<int> n,p;
        
        for(int i = 0;i<arr.size();++i){
            if(arr[i]<0){
                n.emplace_back(arr[i]);
            }
            else{
                p.emplace_back(arr[i]);
            }
        }
        int k = 0;
        for(int i=0;i<n.size();++i){
            arr[k++] = p[i];
            arr[k++] = n[i];
        }
        
        return arr; 
    }
};