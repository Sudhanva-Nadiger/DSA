class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int,int> mp;
        int enough = arr.size()/4;
        for(int i = 0;i<arr.size();++i){
            mp[arr[i]]++;
            if(mp[arr[i]]>enough){
                return arr[i];
            }
        }
        
        return 0;
    }
};