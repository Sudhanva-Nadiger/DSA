func majorityElement(nums []int) int {
    mp := make(map[int]int)
    n := len(nums)
    
    for _, val := range nums {
        mp[val]++
        if mp[val] > n/2 {
            return val
        }
    }
    
    return -1
}