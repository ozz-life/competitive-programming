#include <bits/stdc++.h>
#include <ranges>
#include <algorithm>
using namespace std;
using std::cout;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pi;

#define all(x) (x).begin(), (x).end()
const char ENDL = '\n';

ll n, m;

bool canCreateHeap(ll n, ll m) {
    if (m % 2 != 0) {
        return false;
    }

    if (m > n) {
        return false;
    }

    if (n % m != 0) {
        return false;
    }

    while (n > m) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            return false;
        }
    }

    return n == m;
}

void solve()
{
    cin >> n >> m;

    if (canCreateHeap(n, m)) {
        cout << "YES" << ENDL;
    } else {
        cout << "NO" << ENDL;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    ll num_test_cases;
    cin >> num_test_cases;
    for (int current_case = 1; current_case <= num_test_cases; current_case++)
    {
        solve();
    }

    return 0;
}