cpdomains = ["900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"]

/**
 * @param {string[]} cpdomains
 * @return {string[]}
 */
// var subdomainVisits = function (cpdomains) {

//     let visitCounts = {}

//     for (let i = 0; i < cpdomains.length; i++) {
//         let [visits, domains] = cpdomains[i].split(' ')
//         let subdomains = domains.split('.')

//         while (subdomains.length) {
//             let subdomain = subdomains.join('.')
//             console.log(subdomain)

//             visitCounts[subdomain] = visitCounts.hasOwnProperty(subdomain) ?
//                 Number(visitCounts[subdomain]) + Number(visits) :
//                 visits;

//             subdomains.shift()
//         }
//     }

//     return Object.keys(visitCounts).map((key) => `${visitCounts[key]} ${key}`);
// };

////////////////////////////////////////////////////////////////////////////////

var subdomainVisits = function (cpdomains) {
    let map = new Map()
    for (let i = 0; i < cpdomains.length; i++) {
        let [count, url] = cpdomains[i].split(' ')
        // map.set(url, +(map.get(url) ?? 0) + +count)
        map.set(url, (map.get(url) || 0) + +count) // так быстрее, чем ??

        while (url.indexOf('.') > -1) {
            url = url.slice(url.indexOf('.') + 1)
            map.set(url, +(map.get(url) ?? 0) + +count)
        }
    }

    let arr = []
    map.forEach((count, domain) => {
        arr.push(`${count} ${domain}`)
    }) 
    
    return arr
}

////////////////////////////////////////////////////////////////////////////////

console.log(subdomainVisits(cpdomains));