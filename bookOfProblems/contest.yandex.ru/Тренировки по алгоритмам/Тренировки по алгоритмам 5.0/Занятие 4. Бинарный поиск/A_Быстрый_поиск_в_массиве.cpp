#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, k;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int l, r;
        cin >> l >> r;
		auto lIdx = lower_bound(a.begin(), a.end(), l) - a.begin();
        auto rIdx = upper_bound(a.begin(), a.end(), r) - a.begin();
        cout << rIdx - lIdx << " ";
    }
    cout << endl;
}

int main() {
    solve();
    return 0;
}