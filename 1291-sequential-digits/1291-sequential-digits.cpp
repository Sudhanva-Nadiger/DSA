class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        queue<int> q;
        
        for(int i = 1; i <= 9; i++) q.push(i);
        
        while(q.size()) {
            int f = q.front();
            q.pop();
            
            if(low <= f && f <= high) {
                ans.push_back(f);
            }
            
            int lastDig = f%10;
            
            if(lastDig == 9) continue;
            
            int nextNum = f*10 + (lastDig+1);
            
            if(nextNum <= high) {
                q.push(nextNum);
            }
        }
        
        return ans;
    }
};