class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map<int,int> mp;
        
        int i = 1;
        
        for(int& e:nums){
            mp[e]++;
        }
        
        while(mp.find(i) != mp.end()){
            i++;
        }
        
        return i;
        
    }
};