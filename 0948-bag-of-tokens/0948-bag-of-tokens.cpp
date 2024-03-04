class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int p) {
        if(tokens.size() == 0){
            return 0;
        }
        sort(tokens.begin(),tokens.end());
        if(tokens[0] > p){
            return 0;
        }
        
        int i = 0;
        int j = tokens.size()-1;
        int score = 0;
        int ans = 0;
        while(i<=j and (p >= tokens[i] or score > 0)){
            while(i <= j and p >= tokens[i]){
                p -= tokens[i];
                i++;
                score++;
            }
            
            ans = max(ans,score);
            
            if(i <= j and score > 0){
                score--;
                p += tokens[j];
                j--;
            }
        }
        
        return ans;
        
    }
};