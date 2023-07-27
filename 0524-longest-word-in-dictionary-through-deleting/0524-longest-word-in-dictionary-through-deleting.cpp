class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        int i = 0;
        int n = dictionary.size();
        vector<int> index(n, 0);
        int ans = -1;
        
        while(i < s.size()) {
            int currChar = s[i];
            for(int j = 0; j < n; j++) {
                int pos = index[j];
                if(pos != -1) {
                    if(pos == dictionary[j].size()-1 && currChar == dictionary[j][pos]) {
                        if(ans == -1) {
                            ans = j;
                        }else {
                            if(dictionary[j].size() > dictionary[ans].size()) {
                                ans = j;
                            }else if(dictionary[j].size() == dictionary[ans].size()) {
                                if(dictionary[j] < dictionary[ans]) {
                                    ans = j;
                                }
                            }
                        }
                    }else {
                        if(currChar == dictionary[j][pos]) {
                            index[j]++;
                        }
                    }
                }
            }
            
            i++;
        }
        
        if(ans == -1) return "";
        
        return dictionary[ans];
    }
};