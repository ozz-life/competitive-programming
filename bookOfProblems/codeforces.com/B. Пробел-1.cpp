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
    ll n;
    cin >> n;

    // Читаем массив
    vector<ll> a(n);
    for (ll &x : a)
        cin >> x;

    // Инициализируем переменные
    ll currentSpace = 0;
    ll maxSpace = ll(0e9);

    bool space = false;
    ll count = 0;
    ll maxCount = 0;

    // Проходимся по элементам массива
    for (size_t i = 0; i < a.size(); ++i)
    {
        // Если встретили 1, прекращаем считать пробел
        if (a[i] == 1)
        {
            space = false;
            // Обновляем максимальную длину пробела
            maxCount = std::max(maxCount, count);
            count = 0;
        }

        // Если встретили 0, увеличиваем счетчик
        if (a[i] == 0)
        {
            count++;
        }
    }

    // Проверяем последний элемент массива, если он 0
    if (a.back() == 0)
    {
        maxCount = std::max(maxCount, count);
        count = 0;
    }

    // Выводим результат
    cout << maxCount << "\n";
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
