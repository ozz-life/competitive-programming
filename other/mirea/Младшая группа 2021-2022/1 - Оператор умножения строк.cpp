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

ll n, m, k, t, q, l, r, x, y, z;
ll answer;
const ll template_array_size = 1e6 + 8432;
ll arrA[template_array_size];
ll arrB[template_array_size];
ll arrC[template_array_size];
std::string s;

std::string operator*(std::string s, int64_t n)
{
    string res = s;
    for (int i = 1; i < n; ++i)
    {
        res += s;
    }
    return res;
}

void solve()
{
    cout << "abc"s * 4 << endl;
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

    int num_test_cases = 1;
    // cin >> num_test_cases;
    for (int current_case = 1; current_case <= num_test_cases; current_case++) // проходим по всем тест-кейсам
    {
        // cout << "Case #" << current_case << ": ";
        solve();
    }

    return 0;
}
