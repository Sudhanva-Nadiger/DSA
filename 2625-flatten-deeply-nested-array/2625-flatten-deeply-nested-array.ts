type MultiDimensionalArray = (number | MultiDimensionalArray)[];

var flat = function (arr:  MultiDimensionalArray, n: number):  MultiDimensionalArray {
    if(n == 0) {
        return arr;
    }
    
    const res: MultiDimensionalArray = [];
    
    arr.forEach(val => {
        if(Array.isArray(val)) {
            res.push(...flat(val, n-1));
        } else {
            res.push(val);
        }
    })
    
    return res;
};