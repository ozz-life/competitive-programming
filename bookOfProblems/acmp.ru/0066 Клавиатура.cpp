#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main()
{
    string s = "qwertyuiopasdfghjklzxcvbnmq";
    char c;
    cin >> c;

    int n = s.find(c);
    if (n == 25)
    {
        cout << "q";
    }
    else
    {
        cout << s[n + 1];
    }
}