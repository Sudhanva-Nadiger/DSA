class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int index = -1;
        bool first = 1;
        for(int i = 0;i<nums.size();i++)
        {
             if(nums[i]>=0 and first){
                 index = i;
                 first = 0;
             }
            nums[i] = nums[i]*nums[i];
        }
        if(index == -1){
            reverse(nums.begin(),nums.end());
            return nums;
        }
        vector<int> ans ;
        int j = index-1;
        while(index<nums.size() and j>=0){
            if(nums[j]<nums[index]){
                ans.push_back(nums[j]);
                j--;
            }
            else{
                ans.push_back(nums[index]);
                index++;
            }
        }
        
        while(j>=0){
            ans.push_back(nums[j]);
            j--;
        }
        
        while(index < nums.size()){
            ans.push_back(nums[index]);
            index++;
        }
        
        
        return ans;
    }
};