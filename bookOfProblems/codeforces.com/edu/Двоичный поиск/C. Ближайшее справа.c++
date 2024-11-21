#include <bits/stdc++.h>
using namespace std;

int find_upper(vector<int> &a, int x) // max i: a[i] >= x
{
    int l = -1;            // a[l] < x
    int r = (int)a.size(); // a[r] >= x
    while (r > l + 1)
    {
        int m = (l + r) / 2; // m > l, m < r
        if (a[m] < x)
        {
            l = m;
        } else {
            r = m;
        }
    }
    return r;
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
        cout << find_upper(a, x) + 1 << "\n";
    }

    return 0;
}