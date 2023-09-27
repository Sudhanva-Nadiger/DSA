func f(m int, n int, dp [][]int) int {
    if m == 0 || n == 0 {
        return 0
    }
    
    if m == 1 && n == 1 {
        return 1
    }
    
    if dp[m][n] != -1 {
        return dp[m][n]
    }
    
    up := f(m-1, n, dp)
    left := f(m, n-1, dp)
    
    dp[m][n] = up + left
    return dp[m][n]
}

func uniquePaths(m int, n int) int {
    maxN := 101
    dp := make([][]int, maxN)
    for i := range dp {
        dp[i] = make([]int, maxN)
        
        for j := 0; j < maxN; j++ {
            dp[i][j] = -1
        }
    }
    
    return f(m, n, dp)
}