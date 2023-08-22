class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        int n = messages.size();
        unordered_map<string, int> mp;
        
        for(int i = 0; i < n; i++) {
            stringstream ss(messages[i]);
            string word;
            
            while(!ss.eof()) {
                getline(ss, word, ' ');
                mp[senders[i]] += (word.size() > 0); 
            }
        }
        
        string ans = "";
        int maxCount = 0;
        
        for(auto it : mp) {
            if(it.second > maxCount) {
                maxCount = it.second;
                ans = it.first;
            } else if(it.second == maxCount) {
                ans = max(ans, it.first);
            }
        }
        
        return ans;
    }
};