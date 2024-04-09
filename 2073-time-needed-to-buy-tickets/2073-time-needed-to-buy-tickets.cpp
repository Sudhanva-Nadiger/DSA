class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int,int>> q;
        
        for(int i=0;i<tickets.size();++i){
            q.push({tickets[i],i});
        }
        int ans = 0;
        while(1){
            pair<int,int> x = q.front();
            q.pop();
            x.first = x.first-1;
            ans++;
            if(x.first>0){
                q.push(x);
            }
            else{
                if(x.second == k){
                    return ans;
                }
            }
            
        }
        
        return ans;
    }
};