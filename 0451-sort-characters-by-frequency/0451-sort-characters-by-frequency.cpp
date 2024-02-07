class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        
        for(auto c : s){
            mp[c]++;
        }
        
        sort(s.begin(),s.end(),[&mp](char& a,char& b){
            int frq1 = mp[a];
            int frq2 = mp[b];
            
            if(frq1 == frq2){
                return a>b;
            }
            
            return frq1 > frq2;
        });
        
        return s;
    }
};