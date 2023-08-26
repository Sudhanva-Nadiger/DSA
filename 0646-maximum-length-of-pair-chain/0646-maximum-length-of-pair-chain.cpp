class Solution {
public:
    int dp[1001][1002];
    int solve(vector<vector<int>>& pairs,int currentIndex,int prevIndex){
        if(currentIndex >= pairs.size()){
            return 0;
        }
        
        if(dp[currentIndex][prevIndex+1]){
            return dp[currentIndex][prevIndex+1];
        }
        
        int includeCurrentElement = 0;
        if(prevIndex == -1 or pairs[prevIndex][1] < pairs[currentIndex][0]){
            includeCurrentElement = 1+solve(pairs,currentIndex+1,currentIndex);
        }
        int excludeCurrentElement = solve(pairs,currentIndex+1,prevIndex);
        
        return dp[currentIndex][prevIndex+1] = max(includeCurrentElement,excludeCurrentElement);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(begin(pairs),end(pairs),[](auto& a,auto& b){
            if(a[0] == b[0]){
                return a[1] <= b[1];
            }
            
            return a[0] < b[0];
        });
        
        
        
        return solve(pairs,0,-1);
    }
};