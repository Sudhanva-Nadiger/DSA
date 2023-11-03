class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int index = 0;
        int count = 0;
        vector<string> ans;
        
        for(int i = 1; i<= n; i++){
            if(index == target.size()){
                break;
            }
            if(i == target[index]){
                for(int j = 0; j < count; j++){
                    ans.push_back("Push");
                }
                for(int j = 0; j < count; j++){
                    ans.push_back("Pop");
                }
                ans.push_back("Push");
                index++;
                count = 0;
            }else{
                count++;
            }
        }
        
        return ans;
    }
};