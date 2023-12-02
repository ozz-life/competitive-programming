#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int k = 0;
    while (n > 0)
    {
        k += n % 2;
        n /= 2;
    }

    if (k == 1) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}