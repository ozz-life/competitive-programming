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
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n)-1; i >= 0; --i)

#define inp(x)                                                                 \
  for (auto &i : x)                                                            \
    cin >> i;
#define print(x)                                                               \
  for (auto i : x)                                                             \
    cout << i << " ";
#define pprint(x)                                                              \
  for (auto [i, j] : x)                                                        \
  cout << i << " " << j

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
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
 * Math
 ******************************************************************************/

inline bool isEven(const int &x) { return (x & 1) == 0; }
inline bool isOdd(const int &x) { return x & 1; }

int integerDivisionCeil(int numerator, int denominator) {
  if (numerator == 0) {
    return 0;
  }
  return (numerator - 1) / denominator + 1;
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
std::vector<int64_t> z_function(std::string s) {
  int64_t n = s.size();
  std::vector<int64_t> z(n);
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

std::string removeLeadingZeros(const std::string &s) {
  auto it = s.begin();

  while (it != s.end() && *it == '0') {
    ++it;
  }

  return std::string(it, s.end());
}

std::string addLeadingZeros(std::string &s, int64_t n) {
  std::string result;
  for (int i = 0; i < n; ++i) {
    result += '0';
  }

  result += s;
  return result;
}

/*
 * Debug
 ******************************************************************************/

#define watch(x) cout << #x << " = " << (x) << endl;
#define d(x) cout << #x << " == " << (x) << endl;

template <typename A, typename B> string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string &s) { return '"' + s + '"'; }

string to_string(const char *s) { return to_string((string)s); }

string to_string(bool b) { return (b ? "true" : "false"); }

string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template <size_t N> string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}

template <typename A> string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

template <typename A, typename B> string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

/*
 * Solve
 ******************************************************************************/

// 5
// 0 0 0 0 0 
// 0 0 0 0 1 
// 1 1 0 0 0 
// 0 0 0 0 0 
// 0 0 0 0 0 

// Оutput 3

// Функция для подсчета количества ребер в ориентированном графе по его матрице смежности
int countEdges(const vector<vector<int>>& adjacencyMatrix) {
    int edges = 0; // Инициализируем счетчик ребер

    // Проходим по всем элементам матрицы смежности
    for (const auto& row : adjacencyMatrix) {
        for (int value : row) {
            // Если значение элемента равно 1, увеличиваем счетчик ребер
            if (value == 1) {
                edges++;
            }
        }
    }

    return edges; // Возвращаем количество ребер
}

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> matrix(n, vector<int>(n, 0));

  // Считываем матрицу смежности
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> matrix[i][j];
    }
  }

  // Выводим количество петель в графе
  cout << countEdges(matrix) << endl;
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