/** 
 * Forward declaration of isBadVersion API.
 * @param   version   your guess about first bad version
 * @return 	 	      true if current version is bad 
 *			          false if current version is good
 * func isBadVersion(version int) bool;
 */

 func firstBadVersion(n int) int {
    l := -1
    r := math.MaxInt32
    for r - l > 1 {
        m := l + (r - l) >> 1
        if isBadVersion(m) {
            r = m
        } else {
            l = m
        }
    }

    return r
}