func isMonotonic(nums []int) bool {
    n := len(nums)
    if n <= 2 {
        return true
    }
    
    ok := true
    
    for i := 1; i < n && ok; i++ {
        if nums[i] < nums[i-1] {
            ok = false
        }
    }
    
    if ok {
        return true
    }
    
    ok = true
    for i := 1; i < n && ok; i++ {
        if nums[i] > nums[i-1] {
            ok = false
        }
    }
    
    return ok
}