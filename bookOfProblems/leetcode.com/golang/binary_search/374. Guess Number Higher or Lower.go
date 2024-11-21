/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * func guess(num int) int;
 */

 func guessNumber(x int) int {
    l := 0
    r := x
    m := 0
    
    for l <= r {
        m = l + (r - l) >> 1
        guessResponse := guess(m);
        if guessResponse == -1 {
            r = m - 1
        } else if guessResponse == 1 {
            l = m + 1
        } else {
            break
        }
    }
    
    return m
}