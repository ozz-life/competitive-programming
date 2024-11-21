#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x;
    cin >> x;

    if (x == 1)
    {
        cout << 0;
    }
    else if (x % 2 == 0)
    {
        cout << x / 2;
    }
    else
    {
        cout << x;
    }
}