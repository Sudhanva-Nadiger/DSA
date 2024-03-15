class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int pos = 0;
        int check = 0;
        int product = 1;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]!=0){
                product *= nums[i];
            }
            else
            {
               pos = i;
               check++;
            }
        }
        vector<int> ans (nums.size(),0);
        if(check >= 2){
            return ans;
        }
        if(check == 1){
            ans[pos]=product;
            return ans;
        }
        else
        {
            for(int i =0;i<nums.size();i++){
                if(nums[i]<0)
                {
                    nums[i] = abs(nums[i]);
                     ans[i] = -1*product * (float)pow(nums[i],-1);
                }
                else
                {
                    ans[i] = product * (float)pow(nums[i],-1);
                }
            }
        }
        
        return ans;
        
    }
};