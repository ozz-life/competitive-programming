// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     int x;
//     cin >> x;

//     if (x == 1)
//     {
//         cout << 0;
//     }
//     else if (x % 2 == 0)
//     {
//         cout << x / 2;
//     }
//     else
//     {
//         cout << x;
//     }
// }

/**
 * @param {number} n
 * @return {number}
 */
var numberOfCuts = function(n) {
    if (n == 1) { return 0 }
    else if ( n % 2 == 0) return n / 2
    else return n
};