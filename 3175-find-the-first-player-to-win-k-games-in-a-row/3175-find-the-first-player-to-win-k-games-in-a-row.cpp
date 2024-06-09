class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        map<int, int> mp;
        
        for(int i = 0; i < skills.size(); i++) {
            mp[skills[i]] = i;
        }
        
        int maxi = skills[0], count = 0;
        
        for(int i = 1; i < skills.size(); i++) {
            if(maxi > skills[i]) {
                count++;
            } else {
                count = 1;
                maxi = skills[i];
            }
            
            if(count == k) return mp[maxi];
        }
        
        return mp[maxi];
    }
};