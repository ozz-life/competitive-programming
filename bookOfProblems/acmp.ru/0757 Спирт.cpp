#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main()
{
    // c2h5(oh)
    long long c, h, o;
    cin >> c >> h >> o;

    c = c / 2;
    h = h / 6;
    o = o / 1;

    cout << min(min(c,h), o);
}