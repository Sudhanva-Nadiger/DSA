import("sort")

type Pair struct {
    val int
    index int
}

func twoSum(nums []int, target int) []int {
    var arr []Pair
    
    for i, val := range nums {
        arr = append(arr, Pair{val, i})
    }
    
    sort.Slice(arr, func(a int, b int) bool {
            return arr[a].val < arr[b].val;
        })
    
    i, j := 0, len(arr)-1
    
    var res []int
    // fmt.Print(arr)
    
    for i < j {
        sum := arr[i].val + arr[j].val;
        if sum == target {
            res = append(res, arr[i].index)
            res = append(res, arr[j].index)
            break
        } else if sum < target {
            i++
        } else {
            j--
        }
    }
    
    return res
}