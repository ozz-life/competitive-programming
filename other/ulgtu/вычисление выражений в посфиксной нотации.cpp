// Если нужно Преобразовать в постфиксную через алгоритм сортировочной станции

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pi;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    stack<int> operands;
    string token;
    while (cin >> token)
    {
        if (isdigit(token[0]))
        {
            operands.push(stoi(token));
        }
        else
        {
            int b = operands.top();
            operands.pop();
            int a = operands.top();
            operands.pop();

            if (token == "+")
            {
                operands.push(a + b);
            }
            else if (token == "-")
            {
                operands.push(a - b);
            }
            else if (token == "*")
            {
                operands.push(a * b);
            }
            else if (token == "/")
            {
                operands.push(a / b);
            }
        }
    }

    cout << operands.top();

    return 0;
}