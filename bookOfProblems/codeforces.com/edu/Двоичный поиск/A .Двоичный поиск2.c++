#include <bits/stdc++.h>
using namespace std;

int find_lower(vector<int> &a, int x) // max i: a[i] <= x
{
    int l = -1;            // a[l] <= x
    int r = (int)a.size(); // a[r] > x
    while (r > l + 1)
    {
        int m = (l + r) / 2; // m > l, m < r
        if (a[m] <= x)
        {
            l = m;
        } else {
            r = m;
        }
    }
    return l;
}

bool find(vector<int> &a, int x)
{
    int i = find_lower(a, x);
    return i >= 0 && a[i] == x;
}

int main()
{
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    while (k--)
    {
        int x;
        cin >> x;

        if (find(a, x))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}