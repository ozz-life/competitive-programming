#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m1, m2, m3;
    cin >> m1 >> m2 >> m3;

    if ((m1 >= 94 && m1 <= 727) &&
        (m2 >= 94 && m2 <= 727) &&
        (m3 >= 94 && m3 <= 727))
    {
        cout << max(max(m1, m2), m3);
    }
    else
    {
        cout << "Error";
    }
}