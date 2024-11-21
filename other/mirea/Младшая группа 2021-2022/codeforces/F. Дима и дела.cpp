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

// void solve()
// {
//     ll n, k;
//     cin >> n >> k;
//     vector<ll> vec(n);
//     for (ll i = 0; i < n; ++i)
//     {
//         cin >> vec[i];
//     }

//     ll mn = ll(1e9);
//     ll ans = 0;
//     for (ll i = 0; i < k; ++i)
//     {
//         ll cur = 0;
//         for (ll j = i; j < n; j += k)
//         {
//             cur += vec[j];
//         }
//         if (cur < mn)
//         {
//             mn = cur;
//             ans = i;
//         }
//     }
//     cout << ans + 1 << "\n";
// }

void solve()
{
    ll n, k;
    cin >> n >> k;

    vector<ll> vec(n); // вектор для хранения силы ругани для каждого дела
    for (ll i = 0; i < n; ++i)
    {
        cin >> vec[i];
    }

    ll mn = ll(1e9); // переменная для хранения минимальной суммы силы ругани
    ll ans = 0; // переменная для хранения номера дела, с которого нужно начинать

    // перебираем возможные варианты начала выполнения дел
    for (ll i = 0; i < k; ++i)
    {
        ll cur = 0; // переменная для хранения суммарной силы ругани при текущем варианте начала выполнения дел

        // обрабатываем каждое k-ое дело до конца
        for (ll j = i; j < n; j += k)
        {
            cur += vec[j];
        }

        // если суммарная сила ругани при текущем варианте начала выполнения дел меньше, чем ранее найденная минимальная сумма,
        // обновляем значения переменных mn и ans
        if (cur < mn)
        {
            mn = cur;
            ans = i;
        }
    }

    // выводим номер дела, с которого нужно начинать
    cout << ans + 1 << "\n";
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
