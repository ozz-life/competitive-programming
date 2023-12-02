#include <fstream>
#include <string>

using namespace std;

ifstream cin("input.txt");
ofstream cout("output.txt");

int n, m;
string s;

void rec(int idx, int k)
{
    if (idx == n)
    {
        if (k == m)
            cout << s << endl;
        return;
    }

    if ((idx == 0 || (idx > 0 && s[idx-1] != '*')) && k < m)
    {
        s[idx] = '*';
        rec(idx + 1, k + 1);
    }
    s[idx] = '.';
    rec(idx + 1, k);	
}

int main()
{
    cin >> n >> m;
    s = "";
    for (int i = 0; i < n; i++)
        s += '.';

    rec(0, 0);

    return 0;
}