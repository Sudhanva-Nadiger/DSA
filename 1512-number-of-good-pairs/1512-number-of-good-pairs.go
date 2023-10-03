func numIdenticalPairs(nums []int) int {
    n := len(nums)
    ans := 0
    mp := make(map[int]int)
    
    for i := 0; i < n; i++ {
        ans += mp[nums[i]]
        mp[nums[i]]++
    }
    return ans
}