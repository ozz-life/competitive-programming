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
          Author: Stanilav "Oz" Ozeransky | Site: https:://ozz.life/

We are what we think.
All that we are arises with our thoughts.
With our thoughts we make the world.
Speak or act with a pure mind
And happiness will follow you
As your shadow, unshakable. ― Gautama Buddha

*/

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

typedef int64_t ll;
typedef uint64_t ull;
typedef vector<int64_t> vi;
typedef pair<int64_t, int64_t> pi;

#define FOR(s, e, i) for (int64_t i = s; i < e; ++i)
#define FORE(s, e, i) for (int64_t i = s; i <= e; ++i)
#define ROF(e, s, i) for (int64_t i = e; i >= s; --i)

#define inp(x)        \
    for (auto &i : x) \
        cin >> i;
#define print(x)     \
    for (auto i : x) \
        cout << i << " ";
#define pprint(x)         \
    for (auto [i, j] : x) \
    cout << i << " " << j

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define mine(v) *std::min_element(all(v));
#define maxe(v) *std::max_element(all(v));

const char ENDL = '\n';
#define YES cout << "YES" << '\n';
#define NO cout << "NO" << '\n';
#define YN(x) cout << (x ? "YES\n" : "NO\n"

#define pb push_back
#define mp make_pair

/*
 * Solve
 ******************************************************************************/

void solve()
{
    int a, b, c, x, y, z;
    std::cin >> a >> b >> c >> x >> y >> z;

    std::vector<std::string> kings;

    int Barley = a * x;
    int Hops = b * y;
    int Malt = c * z;
    //int max = std::max(Barley, std::max(Hops, Malt));
    int max = std::max({Barley, Hops, Malt});

    if (Barley == max) {
        kings.push_back("Barley");
    }
    if (Hops == max) {
        kings.push_back("Hops");
    }
    if (Malt == max) {
        kings.push_back("Malt");
    }

    std::sort(kings.begin(), kings.end());

    for (const auto& king : kings) {
        std::cout << king << " ";
    }
    std::cout << std::endl;
}

/*
 * Main
 ******************************************************************************/

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
    // auto time_start = steady_clock::now();

    int64_t num_test_cases = 1;
    //cin >> num_test_cases;
    for (int64_t current_case = 1; current_case <= num_test_cases; current_case++) // проходим по всем тест-кейсам
    {
        // cout << "Case #" << current_case << ": ";
        solve();
    }

    // auto time_end = steady_clock::now();
    // cout << duration_cast<milliseconds>(time_end - time_start).count();

    return 0;
}