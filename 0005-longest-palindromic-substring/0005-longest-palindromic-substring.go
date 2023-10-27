func longestPalindrome(s string) string {
    n := len(s);
    var dp [1000][1000]int
    
    start, end := 0, -1
    
    for g := 0; g < n; g++ {
        for i, j := 0, g; j < n; i, j = i+1, j+1 {
            dp[i][j] = 0
            
            if g == 0 {
                dp[i][j] = 1;
            } else if g == 1 {
                if s[i] == s[j] {
                    dp[i][j] = 1;
                }
            } else {
                if s[i] == s[j] && dp[i+1][j-1] == 1 {
                    dp[i][j] = 1
                }
            }
            
            if dp[i][j] == 1 {
                if (end - start) < (j - i) {
                    end = j;
                    start = i;
                }
            }
        }
    }
    
    return s[start:end+1]
}