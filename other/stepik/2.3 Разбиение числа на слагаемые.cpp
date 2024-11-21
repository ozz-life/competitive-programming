
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;


/*
 * Solve
 ******************************************************************************/

vector<int> a;
int sum[40];
int n, m;

void print_terms(int left, int min = 0, int i = 0){
    if (left < 0 || min == n)
        return;
    sum[i] = min;
    if (min != 0)
    {
        print_terms(left - min, min, i + 1);
    }
    print_terms(left - 1, min + 1, i);
    if (left == 0)
    {
        for (int j = 0; j <= i; ++j)
            std::cout << sum[j] << (j != i ? '+' : '\n');
    }
        
}

void solve()
{
    n = 7;
    print_terms(n);
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
    //setlocale(LC_ALL, "Russian");
    // auto time_start = steady_clock::now();

    int64_t num_test_cases = 1;
    //cin >> num_test_cases;
    for (int64_t current_case = 1; current_case <= num_test_cases; current_case++) // проходим по всем тест-кейсам
    {
        // cout << "Case #" << current_case << ": ";
        solve();
    }

   //auto time_end = steady_clock::now();
    //cout << duration_cast<milliseconds>(time_end - time_start).count();

    return 0;
}