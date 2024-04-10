class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& nums) {
        int n = nums.size();
        
        sort(nums.begin(),nums.end());
        vector<int> ans(n,0);
        
        queue<int> q;
        
        for(int i = 0;i<n;++i){
            q.push(i);
        }
        
        for(int i = 0;i<n;++i){
            ans[q.front()] = nums[i];
            q.pop();
            q.push(q.front());
            q.pop();
        }
        
        
        return ans;
        
    }
};