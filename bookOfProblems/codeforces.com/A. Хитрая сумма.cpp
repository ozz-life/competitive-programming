#include <bits/stdc++.h>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pi;

int main()
{
    int64_t num_cases; // количество тестовых случаев
    std::cin >> num_cases;

    for (int64_t i = 0; i < num_cases; ++i)
    {
        int64_t n; // число, для которого рассчитывается ответ
        std::cin >> n;

        int64_t current_power_of_two = 1; // текущая степень двойки, которая вычитается из ответа
        int64_t answer = n * (n + 1) / 2; // исходный ответ, который может изменяться внутри цикла

        // Идем по всем степеням двойки от 1 до n и вычитаем их из ответа.
        while (current_power_of_two <= n)
        {
            answer -= 2 * current_power_of_two;
            current_power_of_two *= 2;
        }

        std::cout << answer << '\n'; // выводим ответ для текущего тестового случая
    }

    return 0;
}