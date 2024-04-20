#include <iostream>
#include <string>

using namespace std;

void solve(int n) {
    for (int i = 0; i < n; i++) {
        string s;
        for (int j = 0; j < n; j++) {
            if ((i + j) % 2 == 0) {
                s += "##";
            } else {
                s += "..";
            }
        }
        cout << s << endl;
        cout << s << endl;
    }
}

int main() {
    int count_test;
    cin >> count_test;

    for (int i = 0; i < count_test; i++) {
        int n;
        cin >> n;
        solve(n);
    }

    return 0;
}
