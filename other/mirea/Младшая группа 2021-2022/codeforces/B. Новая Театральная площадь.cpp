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
#include <ranges>
#include <algorithm>
using namespace std;
using std::cout;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pi;

const char ENDL = '\n';

// ll n, m, k, t, q, l, r, x, y, z;
ll answer;
const ll template_array_size = 1e6 + 8432;
// ll arr[template_array_size];
ll arr1[template_array_size];
ll arrB[template_array_size];
ll arrC[template_array_size];
std::string s;

ll min_cost(ll l, ll x, ll y)
{
    if (2 * x > y)
    {
        ll ans = (l / 2) * y;
        if (l % 2 == 1)
            ans += x;
        return ans;
    }
    else
    {
        return l * x;
    }
}

void solve()
{
    ll n, m, x, y;
    cin >> n >> m >> x >> y;

    ll sum = 0;
    for (ll i = 0; i < n; ++i)
    {
        std::string str;
        cin >> str;
        // str.push_back('*') // Либо вызывать ещё раз функцию sum. Если в конце точки, без звёздочки не закончится обработка

        ll cnt = 0;
        for (ll j = 0; j < m; ++j)
        {
            if (str[j] == '.')
            {
                ++cnt;
            }
            else
            {
                sum += min_cost(cnt, x, y);
                cnt = 0;
            }
        }
        sum += min_cost(cnt, x, y);
    }

    cout << sum << "\n";
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
    // setlocale(LC_ALL, "Russian");

    ll num_test_cases = 1;

    // ll num_test_cases;
    cin >> num_test_cases;
    for (int current_case = 1; current_case <= num_test_cases; current_case++) // проходим по всем тест-кейсам
    {
        // cout << "Case #" << current_case << ": ";
        solve();
    }

    return 0;
}
