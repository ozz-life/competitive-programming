let map = new Map()
let url = "http://tinyurl.com/"

////////////////////////////////////////////////////////////////////////////////

// let encode = function(longUrl) {
//     let key = Date.now().toString()
//     map.set(key,longUrl)
//     return url + key
// }

// let decode = function(shortUrl) {
//     let key = shortUrl.split(url)
//     return map.get(key[1])
// }

////////////////////////////////////////////////////////////////////////////////

let hashMap = new Map()
var encode = function(longUrl) {
    const code = Math.random().toString(32).slice(5)
    const tinyUrl = `https://tinyurl.com/${code}` 
    hashMap.set(tinyUrl,longUrl)
    return tinyUrl
};
var decode = function(shortUrl) {
    return hashMap.get(shortUrl)
};

////////////////////////////////////////////////////////////////////////////////

console.log(decode(url));
console.log(encode(url));