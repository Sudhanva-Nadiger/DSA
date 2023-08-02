class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    int visited[10];
    
    void f(vector<int>& nums) {
        
        if(temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }
        
        for(int i = 0; i < nums.size(); i++) {
            if(!visited[i]) {
                temp.push_back(nums[i]);
                visited[i] = 1;
                f(nums);
                visited[i] = 0;
                temp.pop_back();
            }
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        memset(visited, 0, 10);
        f(nums);
        return ans;    
    }
};