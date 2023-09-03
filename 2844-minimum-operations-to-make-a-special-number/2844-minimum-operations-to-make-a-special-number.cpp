class Solution {
public:
    int minimumOperations(string num) {
        int n = num.size();
        int ans = n;
        for(int i = n-1; i >= 0; i--){
            for(int j = i-1; j >= 0; j--){
                int t = (num[i] - '0') + (num[j] - '0')*10;
                if(t % 25 == 0) ans = min(ans, n - j - 2);  
            }
            if(num[i] == '0') ans = min(ans, n - 1);
        }
        return ans;
    }
};