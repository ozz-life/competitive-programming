#include <bits/stdc++.h>
#include <sys/types.h>

int main()
{
    int n = 1;
    while (n <= 10)
    {
        std::cout << n << "\t" << n * n << "\n"; // выводим число и его квадрат через табуляцию
        ++n;
    }

    ///////////////

    int n = 1;
    do
    {
        std::cout << n << "\t" << n * n << "\n";
        ++n;
    } while (n <= 10);

    ///////////////

    for (initialization; condition; action)
    {
        // тело цикла
    }

    ////////////////
    // Цикл for эквивалентен такому циклу while:
    {
        initialization;
        while (condition)
        {
            // тело цикла
            action;
        }
    }

    ////////////////
    std::string line;
    std::getline(std::cin, line);
    // std::getline(std::cin >> std::ws, line);
    for (char symbol : line)
    {
        std::cout << symbol << "\t" << static_cast<int>(symbol) << "\n";
    }

    ////////////////
    // По стандартной библиотеке итерироваться через size_t
    std::vector<int> data = {1, 2, 3, 4, 5};
    for (size_t i = 0; i != data.size(); ++i)
    {

        std::cout << data[i] << " ";
    }

    for (std::int64_t i = 0; i < std::ssize(data) - 1; ++i) {
    if (data[i] == data[i + 1]) {
        std::cout << "Duplicate value: " << data[i] << "\n";
    }

}
}