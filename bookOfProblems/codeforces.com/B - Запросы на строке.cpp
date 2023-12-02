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
    cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    std::string s;
    std::getline(std::cin >> std::ws, s);

    int m; // кол-во запросов
    std::cin >> m;

    for (int i = 0; i < m; i++)
    {
        int l, r, k;
        std::cin >> l >> r >> k;

        l--;             // Приведение индекса l к нулевой базе
        int len = r - l; // Вычисление длины подстроки
        k %= len;        // Вычисление наименьшего количества позиций для циклического сдвига
                         // Циклический сдвиг символов в подстроке s[l, r) на k позиций вправо
        std::rotate(s.begin() + l, s.begin() + r - k, s.begin() + r);
    }
    std::cout << s << "\n";

    return 0;
}

// input.txt
// abacaba
// 2
// 3 6 1
// 1 4 2