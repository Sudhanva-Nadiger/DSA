class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        
        if(m != n){
            return false;
        }
        
        vector<int> mp1(26), mp2(26);
        unordered_set<char> st1,st2;
        
        for(auto c : word1){
            mp1[c-'a']++;
            st1.insert(c);
        }
        
        for(auto c : word2){
            mp2[c-'a']++;
            st2.insert(c);
        }
        
        if(st1 != st2){
            return false;
        }
        
        if(mp1 == mp2){
            return true;
        }
        
        unordered_map<int,int> map1;
        
        for(auto it : mp1){
            map1[it]++;
        }
        
        for(auto it : mp2){
            int frq = it;
            if(map1.find(frq) != map1.end()){
                if(map1[frq] > 0){
                    map1[frq]--;
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }
        
        return true;
    }
};