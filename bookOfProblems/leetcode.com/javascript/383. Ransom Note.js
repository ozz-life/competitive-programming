/**
 * @param {string} ransomNote
 * @param {string} magazine
 * @return {boolean}
 */
var canConstruct = function (ransomNote, magazine) {

  /*  Find and replace
   *  Time complexity = O(nm)
   *  Space complexity = O(m)
   ****************************************************************************/

  for (const letter of ransomNote) {
    const index = magazine.indexOf(letter)
    if (index == -1) {
      return false
    } else {
      magazine = magazine.replace(letter, '')
    }
  }

  return true

  /* 
   * 
   * 
   ****************************************************************************/

  // if (ransomNote.length > magazine.length) return false;

  // let magazineLetters = {};

  // for (let letter of magazine) {
  //     magazineLetters[letter] = (magazineLetters[letter] || 0) + 1;
  // }

  // for (let letter of ransomNote) {
  //     if ((magazineLetters[letter] || 0) < 1) {
  //         return false;
  //     }

  //     magazineLetters[letter]--;
  // }

  // return true;

  /* Hashmap with object
   * Time complexity = O(m) The complexity depends on the longer of the two
   * strings, magazine
   * Space complexity = O (k) k is the number of distinct characters in magazine
   ****************************************************************************/

  // const availableCharacters = {};

  // for (let char of magazine) {
  //   if (!availableCharacters[char]) {
  //     availableCharacters[char] = 1;
  //   } else {
  //     availableCharacters[char] += 1;
  //   }
  // }
  // console.log('available characters:', availableCharacters);

  // for (let char of ransomNote) {
  //   if (!availableCharacters[char]) {
  //     return false;
  //   } else {
  //     availableCharacters[char] -= 1;

  //     if (availableCharacters[char] < 0) {
  //       return false;
  //     }
  //   }
  // }
  // return true;

  /* 
   * 
   * 
   ****************************************************************************/

  // if (ransomNote.length > magazine.length) return false;
  // // if(magazine.includes(ransomNote)) return true;

  // let magazineArr = [...magazine];
  // console.log(magazineArr);

  // for (let i = 0; i < ransomNote.length; i++) {
  //   let index = magazineArr.indexOf(ransomNote.charAt(i));
  //   if (index === -1) return false;
  //   magazineArr.splice(index, 1);
  // }
  // return true;

  /* 
   * 
   * 
   ****************************************************************************/

};

let magazine = "The quick brown fox jumps over the lazy dog. If the dog barked, was it really lazy?"
let ransomNote = "quick brown"

console.log(canConstruct(ransomNote, magazine));
