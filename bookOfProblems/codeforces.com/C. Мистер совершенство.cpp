/*
            ▒█████  ▒███████▒▒███████▒      ██▓     ██▓  █████▒▓█████
           ▒██▒  ██▒▒ ▒ ▒ ▄▀░▒ ▒ ▒ ▄▀░     ▓██▒    ▓██▒▓██   ▒ ▓█   ▀
           ▒██░  ██▒░ ▒ ▄▀▒░ ░ ▒ ▄▀▒░      ▒██░    ▒██▒▒████ ░ ▒███
           ▒██   ██░  ▄▀▒   ░  ▄▀▒   ░     ▒██░    ░██░░▓█▒  ░ ▒▓█  ▄
           ░ ████▓▒░▒███████▒▒███████▒ ██▓ ░██████▒░██░░▒█░    ░▒████▒
           ░ ▒░▒░▒░ ░▒▒ ▓░▒░▒░▒▒ ▓░▒░▒ ▒▓▒ ░ ▒░▓  ░░▓   ▒ ░    ░░ ▒░ ░
             ░ ▒ ▒░ ░░▒ ▒ ░ ▒░░▒ ▒ ░ ▒ ░▒  ░ ░ ▒  ░ ▒ ░ ░       ░ ░  ░
           ░ ░ ░ ▒  ░ ░ ░ ░ ░░ ░ ░ ░ ░ ░     ░ ░    ▒ ░ ░ ░       ░
               ░ ░    ░ ░      ░ ░      ░      ░  ░ ░             ░  ░
                    ░        ░          ░
                             https:://ozz.life/
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pi;

const char ENDL = '\n';

// ll n, m, k, t, q, l, r, x, y, z;
// ll answer;
// const ll template_array_size = 1e6 + 8432;
// ll a[template_array_size];
// ll b[template_array_size];
// ll c[template_array_size];
// std::string s;

void solve()
{
    int KitCount;
    cin >> KitCount;

    // Инициализируем переменные с бесконечно большими значениями
    int r01 = INT_MAX;
    int r10 = INT_MAX;
    int r11 = INT_MAX;

    for (int j = 0; j < KitCount; j++)
    {
        int minutes;
        string skills;
        cin >> minutes >> skills;

        if (skills == "01")
        {
            r01 = min(r01, minutes);
        }
        if (skills == "10")
        {
            r10 = min(r10, minutes);
        }
        if (skills == "11")
        {
            r11 = min(r11, minutes);
        }
    }

    if (r01 != INT_MAX && r10 != INT_MAX)
    {
        int sum = r01 + r10;

        if (r11 != INT_MAX)
        {
            cout << min(sum, r11) << endl;
        }
        else
        {
            cout << sum << endl;
        }
    }
    else
    {
        if (r11 != INT_MAX)
        {
            cout << r11 << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
}

int main()
{
    // Отключение синхронизация между С и C++ вводом/выводом
    std::ios::sync_with_stdio(false);
    // Отключение синхронизации между cin и cout
    // Важно! При решении интерактивных задач рекомендуется не отключать синхронизацию (или хотя бы держать в голове возможность проблем из-за отключения).
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    // Перенаправление потоков cin/cout с помощью freopen
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll num_test_cases;
    cin >> num_test_cases;
    for (ll current_case = 1; current_case <= num_test_cases; current_case++) // проходим по всем тест-кейсам
    {
        // cout << "Case #" << current_case << ": ";
        solve();
    }

    return 0;
}
