class Solution {
public:
    long long countVowels(string word) {
        long long ans = 0;
        long long n = word.size();
        
        for(long long i = 0; i < n; i++) {
            char it = word[i];
            if(it == 'a' or it =='e' or it == 'i' or it == 'o' or it == 'u') {
                long long l = i+1;
                long long r = max(1ll, n-i);
                
                ans += (l*r);
            }
        }
        
        return ans;
    }
};