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
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    // Решение 1, через ВСЕ перестановки
    // Первые значения, которые склеиваем, а вторые это оставшиеся
    vector<ll> sides1 = {a, b};
    vector<ll> sides2 = {c, d};
    bool ok = false;

    //На каждую перестановку первого вектора, перебери все перестановки второго
    do
    {
        do
        {
            // Сторона первого квадрата == стороне второго квадрата И
            // Сумма оставшихся
            if (sides1[0] == sides2[0] && sides1[0] == sides1[1] + sides2[1])
            {
                ok = true;
            }
        } while (std::next_permutation(all(sides1)));
    } while (std::next_permutation(all(sides2)));

    if (ok) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    // Решение 2. Неполное. Математически исходя из "очевидного" убираем стороны квадрата, которые заведомо неверные
    // ll minim, maxim;
    // maxim = max(a, b);
    // minim = min(a, b);

    // std::string ans[10000];

    // if (((minim + c == maxim) && (maxim == d)) ||
    // ((minim + d == maxim) && (maxim == c)))
    // Не дописано
    //     {
    //         ans[i] = "YES";
    //     }
    // else
    // {
    //     ans[i] = "NO";
    // }
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
    cin >> num_test_cases;
    for (int current_case = 1; current_case <= num_test_cases; current_case++) // проходим по всем тест-кейсам
    {
        // cout << "Case #" << current_case << ": ";
        solve();
    }

    return 0;
}
