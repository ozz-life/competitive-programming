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

void solve()
{

    // MAP
    // По сути мапа это сбалансированное двоичное дерево поиска
    // Вывод идёт в порядке возрастания ключей, строки лексикографически.

    // 1 Посчитать количество символов в строке
    ////////////////////////////////////////////////////////////////////////////

    string s;
    cin >> s;

    map<int8_t, int64_t> m;
    for (int i = 0; i < 4; i++)
    {
        m[s[i]]++;
    }

    // ИЛИ

    for (auto &c : s)
    {
        ++m[c];
    }

    // 2 Даётся n чисел. Посчитайте, сколько раз встречается каждое число
    ////////////////////////////////////////////////////////////////////////////

    std::map<int, int> mp;
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        mp[x] += 1;
    }

    for (auto &element : mp)
    {
        cout << "Число " << element.first << " встречается " << element.second << " раз\n";
    }

    // 3 - Сколько раз встретилась строка? (регистрозависимо)
    ////////////////////////////////////////////////////////////////////////////

    std::map<std::string, int> mp;
    int n;
    cin >> n;
    while (n--)
    {
        std::string str;
        cin >> str;
        ++mp[str];
    }

    for (auto &el : mp)
    {
        cout << el.first << " " << el.second << "\n";
    }

    std::map<std::string, int> freqs;
    std::string word;

    while (std::cin >> word)
    {
        ++freqs[word];
    }

    for (const auto &[word, freq] : freqs)
    {
        std::cout << word << "\t" << freq << "\n";
    }

    // SET
    ////////////////////////////////////////////////////////////////////////////
    
    std::set<int> st;
    for (int i = 0; i < 10; ++i)
    {
        st.insert(rand() % 10);
    }
    for (auto &el : st)
    {
        cout << el << " ";
    }
    // cout << *st.begin() << "\n";
    // st.count(10); // 1 - Если есть, 0 если нет

    // lower_bound - первое число НЕ меньше х
    // upper_bound - первое число, строго больше x
    // lower_bound надо разыменовывать, однако если числа не меньше, чем не будет
    // то выпадет в ошибку
    for (int i = 0; i < 10; ++i)
    {
        auto it = st.lower_bound(i);
        if (it != st.end())
        {
            cout << *it << "\n";
        }
    }

    // Structured binding, a utility of C++17, allows a single definition to define multiple variables with different types simultaneously.
    map<int, string> mp;
    for (auto [key, value] : mp)
    {
        cout << key << value;
    };

    // A nifty trick to simultaneously check if a value exists in a set, and insert it otherwise, is to :
    set<int> s;
    auto [itr, isInserted] = s.insert(2);
    if (isInserted)
        cout << *it;
    else
        cout << "is already present";
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
    setlocale(LC_ALL, "Russian");

    int64_t num_test_cases = 1;
    // cin >> num_test_cases;
    for (int64_t current_case = 1; current_case <= num_test_cases; current_case++) // проходим по всем тест-кейсам
    {
        // cout << "Case #" << current_case << ": ";
        solve();
    }

    return 0;
}
