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

#define all(x) (x).begin(), (x).end()
const char ENDL = '\n';

// ll n, m, k, t, q, l, r, x, y, z;
ll answer;
const ll template_array_size = 1e6 + 8432;
// ll arr[template_array_size];
ll arr1[template_array_size];
ll arrB[template_array_size];
ll arrC[template_array_size];
std::string s;

void solve()
{
    std::string str;
    cin >> str;
    ll n = str.size();
    ll left_ab = str.find("AB");
    ll left_ba = str.find("BA");

    std::reverse(all(str));

    // Индексы переворачиваются вместе со строкой, их надо вернуть хитро
    ll right_ab = n - 1 - str.find("BA") - 1;
    ll right_ba = n - 1 - str.find("AB") - 1;

    bool has_ab = left_ab != std::string::npos;
    bool has_ba = left_ba != std::string::npos;

    ll dist_left = std::abs(left_ab - right_ba);
    ll dist_right = std::abs(left_ba - right_ab);

    if (has_ab && has_ba && (dist_left > 1 || dist_right> 1)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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
    // setlocale(LC_ALL, "Russian");

    ll num_test_cases = 1;
    // cin >> num_test_cases;
    for (int current_case = 1; current_case <= num_test_cases; current_case++) // проходим по всем тест-кейсам
    {
        // cout << "Case #" << current_case << ": ";
        solve();
    }

    return 0;
}
