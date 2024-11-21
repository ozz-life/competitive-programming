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

typedef int64_t ll;
typedef uint64_t ull;
typedef vector<int64_t> vi;
typedef pair<int64_t, int64_t> pi;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

const char ENDL = '\n';
#define YES cout << "YES" << '\n';
#define NO cout << "NO" << '\n';

/*
 * Graph
 ******************************************************************************/

class Graph
{
public:
    Graph(int64_t vertexCount) : adjacencyList(vertexCount) {}

    void addEdge(int64_t vertex1, int64_t vertex2, bool isDirected)
    {
        adjacencyList[vertex1].push_back(vertex2);
        if (!isDirected)
        {
            adjacencyList[vertex2].push_back(vertex1);
        }
    }

    void printGraph() const
    {
        int64_t vertexCount = adjacencyList.size();
        for (int64_t i = 0; i < vertexCount; ++i)
        {
            std::cout << "Vertex " << i + 1 << ": ";
            for (int64_t neighbor : adjacencyList[i])
            {
                std::cout << neighbor + 1 << " ";
            }
            std::cout << std::endl;
        }
    }

    int64_t findDegree(int64_t vertex) const
    {
        return adjacencyList[vertex].size();
    }

private:
    std::vector<std::vector<int64_t>> adjacencyList;
};

/*
 * String
 ******************************************************************************/

// utility function to check whether
// a string is palindrome or not
bool isPalindrome(std::string &str)
{
    // Check for palindrome.
    int64_t n = str.size();
    for (int64_t i = 0; i < n / 2; i++)
        if (str.at(i) != str.at(n - i - 1))
            return false;

    // palindrome string
    return true;
}

// function to find maximum length
// substring which is not palindrome
int64_t longestNonPalindromeSubsequence(std::string &str)
{
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

vector<int64_t> manacher_odd(string s)
{
    int64_t n = (int64_t)s.size();
    vector<int64_t> d(n, 1);
    int64_t l = 0, r = 0;
    for (int64_t i = 1; i < n; i++)
    {
        if (i < r)
            d[i] = min(r - i + 1, d[l + r - i]);
        while (i - d[i] >= 0 && i + d[i] < n && s[i - d[i]] == s[i + d[i]])
            d[i]++;
        if (i + d[i] - 1 > r)
            l = i - d[i] + 1, r = i + d[i] - 1;
    }
    return d;
}

vector<int64_t> manacher_even(string s)
{
    int64_t n = (int64_t)s.size();
    vector<int64_t> d(n, 0);
    int64_t l = -1, r = -1;
    for (int64_t i = 0; i < n - 1; i++)
    {
        if (i < r)
            d[i] = min(r - i, d[l + r - i - 1]);
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
 * Z-функция - это массив z, где z[i] представляет собой длину наибольшего префикса
 * подстроки s[i:], который является также префиксом всей строки s.
 *
 * Использование для поиска всех вхождение образца в строку
 * Построить s:=p+'$'+t
 * z[i] = |p| , когда в t есть вхождение p с позиции i-|p|-1 (вычесть длину образца и единичку)
 *
 * Является ли строка t циклическим сдвигом строки s влево?
 * Запишем два раза строку s. В получившейся строки найти t, как подстроку, если получилось - true
 *
 * Наибольшая грань строки. Одновременно является и префиксом и суффиксом
 * Найти наименьшее i, что i + z[i] =|s| . z[i] - наидлиннейшая грань
 *
 * Количество различных подстрок за O(n^2)
 *
 * @param s Строка, для которой вычисляется Z-функция.
 * @return z - Вектор целых чисел, содержащий значения Z-функции для каждой позиции строки s.
 */
vector<int64_t> z_function(string s)
{
    int64_t n = s.size();
    vector<int64_t> z(n);
    int64_t l = 0, r = 0;
    for (int64_t i = 1; i < n; i++)
    {
        if (i < r)
        {
            z[i] = std::min(r - i, z[i - l]);
        }
        while (s[z[i]] == s[i + z[i]])
        {
            z[i]++;
        }
        if (i + z[i] > r)
        {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

/*
 * Solve
 ******************************************************************************/

std::string createFBString(int64_t n)
{
    std::string fb;
    int64_t fbCount = 0; // Переменная для отслеживания количества добавленных символов
    for (int64_t i = 1; fbCount < n; ++i)
    {
        if (i % 3 == 0 && i % 5 == 0)
        {
            fb += "FB";
            fbCount += 2; // Добавлено 2 символа "FB"
        }
        else if (i % 3 == 0)
        {
            fb += "F";
            fbCount += 1; // Добавлен 1 символ "F"
        }
        else if (i % 5 == 0)
        {
            fb += "B";
            fbCount += 1; // Добавлен 1 символ "B"
        }
    }
    return fb;
}

void solve()
{
    int k;
    cin >> k;

    string s;
    cin >> s;

    string fb = createFBString(100);
    cout << (fb.find(s) != string::npos ? "YES" : "NO") << endl;
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