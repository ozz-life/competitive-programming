#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

#define int int64_t

typedef int64_t ll;
typedef uint64_t ull;
typedef vector<int64_t> vi;
typedef pair<int64_t, int64_t> pi;

#define isz(x) int((x).size())
#define FOR(s, e, i) for (int64_t i = s; i < e; ++i)
#define FORE(s, e, i) for (int64_t i = s; i <= e; ++i)
#define ROF(e, s, i) for (int64_t i = e; i >= s; --i)

#define inp(x)                                                                 \
  for (auto &i : x)                                                            \
    cin >> i;
#define print(x)                                                               \
  for (auto i : x)                                                             \
    cout << i << " ";
#define pprint(x)                                                              \
  for (auto [i, j] : x)                                                        \
  cout << i << " " << j

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define mine(v) *std::min_element(all(v));
#define maxe(v) *std::max_element(all(v));

#define YES cout << "YES" << '\n';
#define NO cout << "NO" << '\n';
#define YN(x) cout << (x ? "YES\n" : "NO\n"

#define pb push_back
#define mp make_pair

/*
 * Solve
 ******************************************************************************/
 
void solve() {
  int n;
  cin >> n;

  string interactor_answer;
  int l = 1, r = n + 1;

  while (l + 1 < r) {

    int m = l + (r - l) / 2;

    cout << "     ? " << m << endl;

    cin >> interactor_answer;
    if (interactor_answer == "<") {
      r = m;
    } else {
      l = m;
    }
  }

  cout << "     ! " << l << endl;
}

/*
 * Main
 ******************************************************************************/

int32_t main() {
  // Отключение синхронизации между С и C++ вводом/выводом
  // std::ios::sync_with_stdio(false);
  // Отключение синхронизации между cin и cout
  // Важно! При решении интерактивных задач рекомендуется не отключать
  // синхронизацию (или хотя бы держать в голове возможность проблем из-за
  // отключения).
  // std::cin.tie(nullptr);
  // std::cout.tie(nullptr);
  // Перенаправление потоков cin/cout с помощью freopen
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  // setlocale(LC_ALL, "Russian");
  // auto time_start = steady_clock::now();

  int64_t num_test_cases = 1;
  // cin >> num_test_cases;
  for (int64_t current_case = 1; current_case <= num_test_cases;
       current_case++) // проходим по всем тест-кейсам
  {
    // cout << "Case #" << current_case << ": ";
    solve();
  }

  // auto time_end = steady_clock::now();
  // cout << duration_cast<milliseconds>(time_end - time_start).count();

  return 0;
}