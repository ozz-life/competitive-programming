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

// typedef int64_t ll;
// typedef uint64_t ull;
// typedef vector<int64_t> vi;
// typedef pair<int64_t, int64_t> pi;

// #define all(x) (x).begin(), (x).end()
// #define rall(x) (x).rbegin(), (x).rend()

// const char ENDL = '\n';
// #define YES cout << "YES" << '\n';
// #define NO cout << "NO" << '\n';

/*
 * Solve
 ******************************************************************************/

void solve()
{
    int64_t n;
    cin >> n;
    string enemy, gregor;
    cin >> enemy >> gregor;

    int64_t answer = 0;
    for (int64_t i = 0; i < n; ++i)
    {
        if (gregor[i] == '1')
        {
            if (i != 0 and enemy[i - 1] == '1')
            {
                answer++;
                enemy[i - 1] = 'D';
                continue;
            }
            if (enemy[i] == '0') {
                answer++;
                enemy[i] = 'D';
                continue;
            }
            if (i + 1 < n and enemy[i + 1] == '1') {
                answer++;
                enemy[i + 1] = 'D';
                continue;
            }
        }
    }

    cout << answer << '\n';
}

/*
 * Main
 ********************************* *********************************************/

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

    // int64_t num_test_cases = 1;
    // OR
    int64_t num_test_cases = 1;
    cin >> num_test_cases;
    for (int64_t current_case = 1; current_case <= num_test_cases; current_case++) // проходим по всем тест-кейсам
    {
        // cout << "Case #" << current_case << ": ";
        solve();
    }

    return 0;
}