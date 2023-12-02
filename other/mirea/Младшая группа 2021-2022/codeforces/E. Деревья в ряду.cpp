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
//         cin >> vec[i];

//     ll mn = ll(1e9); // Изначальный ответ бесконечность
//     ll h = 0;        /// высота первого дерева

//     for (ll fi = 1; fi <= 1000; ++fi) // first, высота первого дерева
//     {
//         ll sum = 0;
//         for (ll i = 0; i < n; ++i)
//         {
//             ll req = fi + i * k;
//             if (req != vec[i])
//             {
//                 ++sum;
//             }  
//         }
//         if (sum < mn)
//         {
//             mn = sum;
//             h = fi;
//         }
//     }

//     cout << mn << "\n";
//     for (ll i = 0; i < n; ++i)
//     {
//         ll req = h + i * k;
//         if (req != vec[i])
//         {
//             if (vec[i] < req)
//             {
//                 cout << "+ " << i + 1 << " " << req - vec[i] << "\n";
//             }
//             else
//                 cout << "- " << i + 1 << " " << vec[i] - req << "\n";
//         }
//     }
// }

void solve()
{
    // Вводим данные
    int n, k;
    cin >> n >> k;
    vector<int> heights(n);
    for (int i = 0; i < n; ++i)
        cin >> heights[i];

    // Находим высоту первого дерева, при которой выполнится условие задачи,
    // и считаем количество операций, которое нужно выполнить
    int min_ops = n, h = -1;
    for (int i = 1; i <= 1000; ++i) {
        int ops = 0;
        for (int j = 0; j < n; ++j) {
            int req_height = i + j * k;
            if (heights[j] != req_height) {
                ++ops;
            }
        }
        if (ops < min_ops) {
            min_ops = ops;
            h = i;
        }
    }

    // Выводим результат
    cout << min_ops << endl;
    for (int i = 0; i < n; ++i) {
        int req_height = h + i * k;
        int diff = abs(req_height - heights[i]);
        if (diff > 0) {
            cout << ((req_height > heights[i]) ? "+ " : "- ");
            cout << (i + 1) << " " << diff << endl;
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
