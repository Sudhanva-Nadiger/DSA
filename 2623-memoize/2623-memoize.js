/**
 * @param {Function} fn
 */
function memoize(fn) {
    let map = {}
    
    return function(...args) {
        let key = JSON.stringify(args);
        
        if(map[key] === null || map[key] === undefined){
            map[key] = Number(fn(...args))
        }
        
        return map[key];
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */