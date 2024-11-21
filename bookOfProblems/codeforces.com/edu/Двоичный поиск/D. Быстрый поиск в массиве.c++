#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <numeric>
#include <cstdio>
#include <list>
#include <cassert>
#include <climits>
using namespace std;

#define ll long long
#define pb push_back
#define loop(a) for(int i = 0; i < a; i++)
#define loopv(i,a) for (int i = 0; i < a; i++)
#define rep(i,a,b) for (int i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define goog(tno) cout << "Case #" << tno <<": "
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

int find_lower(vector<int>& v, int x) {
    int l = -1, r = v.size();
    while (r > l + 1) {
        int m = (l + r) / 2;
        if (v[m] > x) r = m;
        else l = m;
    }
    return l;
}

int find_upper(vector<int>& v, int x) {
    int l = -1, r = v.size();
    while (r > l + 1) {
        int m = (l + r) / 2;
        if (v[m] < x) l = m;
        else r = m;
    }
    return r;
}

int main(void) {
    int n;
    cin >> n;

    vector<int> v(n);
    for (auto& x : v) {
        cin >> x;
    }

    sort(v.begin(), v.end());

    int k;
    cin >> k;

    int l, r;
    while (k--) {
        cin >> l >> r;
        int a = find_upper(v, l);
        int b = find_lower(v, r);

        cout << b - a + 1;
        if (k) cout << " ";
    }
    cout << endl;

    return 0;
}
