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
          Author: Stanislav "Oz" Ozeransky | Site: https:://ozz.life/

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

const char ENDL = '\n';
#define YES cout << "YES" << '\n';
#define NO cout << "NO" << '\n';
#define YN(x) cout << (x ? "YES\n" : "NO\n"

#define pb push_back
#define mp make_pair

/*
 * ASCII
 ******************************************************************************/

constexpr bool is_ascii_letter(char c) noexcept {
  return ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z');
}

constexpr bool is_ascii_number(char c) noexcept { return c >= '0' && c <= '9'; }

constexpr bool is_ascii_lowercase(char c) noexcept {
  return c >= 'a' && c <= 'z';
}

constexpr bool is_ascii_uppercase(char c) noexcept {
  return c >= 'A' && c <= 'Z';
}

/*
 * Scanning/printing the whole vector in a single std::cin/std::cout
 ******************************************************************************/

template <typename T> istream &operator>>(istream &in, vector<T> &a) {
  for (auto &x : a)
    in >> x;
  return in;
};

template <typename T> ostream &operator<<(ostream &out, vector<T> &a) {
  for (auto &x : a)
    out << x << ' ';
  return out;
};

/*
 * Graph
 ******************************************************************************/

class Graph {
public:
  Graph(int64_t vertexCount) : adjacencyList(vertexCount) {}

  void addEdge(int64_t vertex1, int64_t vertex2, bool isDirected) {
    adjacencyList[vertex1].push_back(vertex2);
    if (!isDirected) {
      adjacencyList[vertex2].push_back(vertex1);
    }
  }

  void printGraph() const {
    int64_t vertexCount = adjacencyList.size();
    for (int64_t i = 0; i < vertexCount; ++i) {
      std::cout << "Vertex " << i + 1 << ": ";
      for (int64_t neighbor : adjacencyList[i]) {
        std::cout << neighbor + 1 << " ";
      }
      std::cout << std::endl;
    }
  }

  int64_t findDegree(int64_t vertex) const {
    return adjacencyList[vertex].size();
  }

private:
  std::vector<std::vector<int64_t>> adjacencyList;
};

/*
 * String
 ******************************************************************************/

std::string str_tolower(std::string &s) {
  std::transform(s.begin(), s.end(), s.begin(),
                 [](unsigned char c) { return std::tolower(c); });
  return s;
}

std::string str_toupper(std::string &s) {
  std::transform(s.begin(), s.end(), s.begin(),
                 [](unsigned char c) { return std::toupper(c); });
  return s;
}

bool isPalindrome(std::string &str) {
  int64_t n = str.size();
  for (int64_t i = 0; i < n / 2; i++)
    if (str.at(i) != str.at(n - i - 1))
      return false;

  return true;
}

// function to find maximum length
// substring which is not palindrome
int64_t longestNonPalindromeSubsequence(std::string &str) {
  int64_t n = str.size();
  char ch = str.at(0);

  // to check whether all characters
  // of the string are same or not
  int64_t i = 1;
  for (i = 1; i < n; i++)
    if (str.at(i) != ch)
      break;

  // All characters are same, we can't
  // make a non-palindromic string.
  if (i == n)
    return -1;

  // If string is palindrome, we can make
  // it non-palindrome by removing any
  // corner character
  if (isPalindrome(str))
    return n - 1;

  // Complete string is not a palindrome.
  return n;
}

vector<int64_t> manacher_odd(string s) {
  int64_t n = (int64_t)s.size();
  std::vector<int64_t> d(n, 1);
  int64_t l = 0, r = 0;
  for (int64_t i = 1; i < n; i++) {
    if (i < r)
      d[i] = std::min(r - i + 1, d[l + r - i]);
    while (i - d[i] >= 0 && i + d[i] < n && s[i - d[i]] == s[i + d[i]])
      d[i]++;
    if (i + d[i] - 1 > r)
      l = i - d[i] + 1, r = i + d[i] - 1;
  }
  return d;
}

vector<int64_t> manacher_even(string s) {
  int64_t n = (int64_t)s.size();
  std::vector<int64_t> d(n, 0);
  int64_t l = -1, r = -1;
  for (int64_t i = 0; i < n - 1; i++) {
    if (i < r)
      d[i] = std::min(r - i, d[l + r - i - 1]);
    while (i - d[i] >= 0 && i + d[i] + 1 < n && s[i - d[i]] == s[i + d[i] + 1])
      d[i]++;
    if (i + d[i] > r)
      l = i - d[i] + 1, r = i + d[i];
  }
  return d;
}

/**
 * Вычисляет Z-функцию строки. O(n)
 *
 * Z-функция - это массив z, где z[i] представляет собой длину наибольшего
 * префикса подстроки s[i:], который является также префиксом всей строки s.
 *
 * Использование для поиска всех вхождение образца в строку
 * Построить s:=p+'$'+t
 * z[i] = |p| , когда в t есть вхождение p с позиции i-|p|-1 (вычесть длину
 * образца и единичку)
 *
 * Является ли строка t циклическим сдвигом строки s влево?
 * Запишем два раза строку s. В получившейся строки найти t, как подстроку, если
 * получилось - true
 *
 * Наибольшая грань строки. Одновременно является и префиксом и суффиксом
 * Найти наименьшее i, что i + z[i] =|s| . z[i] - наидлиннейшая грань
 *
 * Количество различных подстрок за O(n^2)
 *
 * @param s Строка, для которой вычисляется Z-функция.
 * @return z - Вектор целых чисел, содержащий значения Z-функции для каждой
 * позиции строки s.
 */
vector<int64_t> z_function(string s) {
  int64_t n = s.size();
  vector<int64_t> z(n);
  int64_t l = 0, r = 0;
  for (int64_t i = 1; i < n; i++) {
    if (i < r) {
      z[i] = std::min(r - i, z[i - l]);
    }
    while (s[z[i]] == s[i + z[i]]) {
      z[i]++;
    }
    if (i + z[i] > r) {
      l = i;
      r = i + z[i];
    }
  }
  return z;
}

/*
 * Solve
 ******************************************************************************/

template <typename T> class PrefSums {
private:
  std::vector<T> pref;

public:
  PrefSums(const std::vector<T> &a) {
    pref = {0};
    for (auto it : a)
      pref.push_back(pref.back() + it);
  }

  T operator()(int l, int r) const { return l > r ? 0 : pref[r + 1] - pref[l]; }

  friend std::ostream &operator<<(std::ostream &out, const PrefSums<T> &psum) {
    for (const auto &x : psum.pref) {
      out << x << ' ';
    }
    return out;
  }
};

// std::vector<int> calculateTotalAscents(const vector<int> &a) {
//   int n = a.size();
//   std::vector<int> prefixSums(n + 1);
//   prefixSums[0] = 0;
//   for (int i = 0; i < n; ++i) {
//     if (i == 0) {
//       prefixSums[i + 1] = prefixSums[i];
//     } else {
//       int difference = a[i] - a[i - 1];
//       if (difference > 0)
//         prefixSums[i + 1] += difference;
//     }
//   }
//   return prefixSums;
// }

std::vector<int> calculateTotalAscents(const vector<int> &a) {
  int n = a.size();
  std::vector<int> prefixSums(n + 1);
  prefixSums[0] = 0;
  for (int i = 0; i < n; ++i) {
    prefixSums[i + 1] = prefixSums[i];
    int difference = a[i] - a[i - 1];
    if (difference > 0)
      prefixSums[i + 1] += difference;
  }
  return prefixSums;
}

int getSum(const vector<int> &prefix_sum, const int &l, const int &r) {
  return prefix_sum[r] - prefix_sum[l];
}

void solve() {
  int N;
  cin >> N;
  std::vector<int> x_coordinates, y_coordinates;
  for (int i = 0; i < N; ++i) {
    int x, y;
    cin >> x >> y;
    x_coordinates.push_back(x);
    y_coordinates.push_back(y);
  }
  int M;
  cin >> M;

  std::vector<int> l_to_r = calculateTotalAscents(y_coordinates);
  std::reverse(y_coordinates.begin(), y_coordinates.end());
  std::vector<int> r_to_l = calculateTotalAscents(y_coordinates);

  for (int i = 0; i < M; ++i) {
    int l, r;
    cin >> l >> r;
    if (r - l >= 0) {
      cout << getSum(l_to_r, l, r) << "\n";
    } else {
      cout << getSum(r_to_l, N - l + 1, N - r + 1) << "\n";
    }
  }
}

/*
 * Main
 ******************************************************************************/

int32_t main() {
  // Отключение синхронизации между С и C++ вводом/выводом
  std::ios::sync_with_stdio(false);
  // Отключение синхронизации между cin и cout
  // Важно! При решении интерактивных задач рекомендуется не отключать
  // синхронизацию (или хотя бы держать в голове возможность проблем из-за
  // отключения).
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
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