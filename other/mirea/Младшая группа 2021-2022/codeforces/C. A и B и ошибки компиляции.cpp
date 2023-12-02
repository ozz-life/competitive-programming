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

void solve()
{
    int64_t n;
    cin >> n;
    std::map<int64_t, int64_t> mp;
    vector<int64_t> vec(n);
    for (int i = 0; i < n; ++i)
    {
        int64_t x;
        cin >> vec[i];
        ++mp[vec[i]];
    }

    for (int i = 0; i < n - 1; ++i)
    {
        int64_t x;
        cin >> x;
        --mp[x];
    }

    int64_t fi, se;
    for (auto &el : mp)
    {
        if (el.second > 0)
        {
            fi = el.first;
        }
    }

    mp.clear();

    for (int i = 0; i < n; ++i)
    {
        ++mp[vec[i]];
    }

    --mp[fi];

    for (int i = 0; i < n - 2; ++i)
    {
        int64_t x; cin >> x;
        --mp[x];
    }

    for (auto &el : mp)
    {
        if (el.second > 0)
        {
            se = el.first;
        }
    }

    cout << fi << "\n" << se << "\n";
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
    setlocale(LC_ALL, "Russian");

    int64_t num_test_cases = 1;
    // cin >> num_test_cases;
    for (int64_t current_case = 1; current_case <= num_test_cases; current_case++) // проходим по всем тест-кейсам
    {
        // cout << "Case #" << current_case << ": ";
        solve();
    }

    return 0;
}
