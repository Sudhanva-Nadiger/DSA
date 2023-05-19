class Solution {
public:
    string largestPalindromic(string num) {
        vector<int> arr(10, 0);
        
        for(char ch : num) {
            arr[ch-'0']++;
        }
        
        for(int i = 0; i < 10; i++) {
            if(arr[i] == num.size()) {
                if(i == 0){
                    return "0";
                }
                return num;
            }
        }
        
        char oddMaxChar = 'a';
        
        for(int i = 0; i < 10; i++) {
            if(arr[i]%2 == 1) {
                if(oddMaxChar == 'a') {
                    oddMaxChar = '0' + i;
                }
                else if(oddMaxChar - '0' < i) {
                    oddMaxChar = '0' + i;
                }
            }
        }
        
        cout << "hello" << endl;
        
        string ans = "";
        
        for(int i = 0; i< 10; i++) {
            if(arr[i]%2==1) {
                arr[i]--;
            }
            
            while(arr[i] > 0) {
                ans.insert(ans.begin(), '0'+i);
                arr[i] -= 2;
            }
        }
        
        cout << oddMaxChar << endl;
        
        while(ans.size() and ans[0] == '0') {
            ans.erase(ans.begin());
        }
        
        
        while(ans.size() and ans[0] == '0') {
            ans.erase(ans.begin());
        }
        
        num = ans;
        
        if(oddMaxChar != 'a'){
            ans.push_back(oddMaxChar);
        }
        
        if(ans.size() == 0){
            return "0";
        }
        
        
        reverse(num.begin(), num.end());
        
        return ans + num ;
    }
};