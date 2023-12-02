////////////////////////////////////////////////////////////////////////////////

var generateTheString = function (n) {
    return n % 2 ? new Array(n).fill('a').join('') : new Array(n - 1).fill('a').join('') + 'b';
};

////////////////////////////////////////////////////////////////////////////////

var generateTheString = function (n) {
    return n % 2 === 0 ? `${'a'.repeat(n - 1)}b` : 'a'.repeat(n);
};
