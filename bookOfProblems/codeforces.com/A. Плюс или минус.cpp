#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int t, a, b, c;

    cin >> t;

    while (t--)
    {
        cin >> a >> b >> c;
        if (a + b == c)
        {
            cout << "+\n";

        }
        else
        {
            cout << "-\n";

        }
    }

    return 0;
}