func f(x float64, n float64) float64 {
    if n == 0 {
        return 1
    }
    
    ans := f(x, n/2)
    if int(n)%2 == 1 {
        return ans*ans*x
    }
    
    return ans*ans
}

func myPow(x float64, n int) float64 {
    flag := (n < 0)
    t := float64(n)
    t = math.Abs(t)
    
    res := f(x, t)
    if flag {
        return 1/res
    }
    
    return res
}