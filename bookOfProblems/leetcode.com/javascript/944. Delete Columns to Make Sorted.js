strs = ["cba","daf","ghi"]

/**
 * @param {string[]} strs
 * @return {number}
 */
function minDeletionSize(strs) {
    let result = 0;
    
    // if array is empty no need to do anything
    if (strs.length === 0) {
        return result;
    }
    
    // since the possible length of the word (horizontal line) is bigger over
    // possible number of words (vertical line) then we need to iterate
    // horizontal -> vertical
    const rowLength = strs[0].length;
    
    // first in our grid iterate horizontally 
    for (let i = 0; i < rowLength; i++) {
        // then iterate vertically
        for (let j = 0; j < strs.length - 1; j++) {
            // if at least one char is sorted wrong then increase our counter
            // and immediately stop the current itteration
            if (strs[j].charCodeAt(i) > strs[j + 1].charCodeAt(i)) {
                result++;
                break;
            }
        }
        
    }
        
    return result;
};

console.log(minDeletionSize(strs));