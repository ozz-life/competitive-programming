#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string arr[13] = {
        "Error",
        "Winter",
        "Winter",
        "Spring",
        "Spring",
        "Spring",
        "Summer",
        "Summer",
        "Summer",
        "Autumn",
        "Autumn",
        "Autumn",
        "Winter",
    };

    if (n < 13)
    {
        cout << arr[n];
    }
    else
    {
        cout << arr[0];
    }
}