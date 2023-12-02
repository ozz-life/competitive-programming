#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main()
{
    long long a, b, c;
    cin >> a >> b >> c;

    cout << 2 * (a * c + b * c + a * b) << " " << a * b * c;
}