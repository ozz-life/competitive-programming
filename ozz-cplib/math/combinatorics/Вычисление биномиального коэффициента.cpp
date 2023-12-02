// Базовая версия, не использовать, исключительно для понимания

#include <iostream>

// Функция для вычисления факториала числа
int factorial(int n)
{
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}

// Функция для вычисления биномиального коэффициента
int binomialCoefficient(int n, int k)
{
    int numerator = factorial(n);
    int denominator = factorial(k) * factorial(n - k);
    int result = numerator / denominator;
    return result;
}

int main()
{
    int n = 5;
    int k = 4;
    int coefficient = binomialCoefficient(n, k);
    std::cout << "Биномиальный коэффициент C(" << n << ", " << k << ") = " << coefficient << std::endl;

    return 0;
}

////////////////////////////////////////////////////////////////////////////////

// Вот процедура расчета, которая считает правильно для n<=67. Иногда и для n>67 при малых k (к примеру, считает C(82,21)=1.83*1019).
uint64_t bcl(int n, int k)
{
    if (k > n / 2)
        k = n - k;
    if (k == 1)
        return n;
    if (k == 0)
        return 1;
    uint64_t r;
    if (n + k >= 90)
    {
        // разрядности может не хватить, используем рекурсию
        r = bcl(n - 1, k);
        r += +bcl(n - 1, k - 1);
    }
    else
    {
        r = 1;
        for (int i = 1; i <= k; ++i)
        {
            r *= n - k + i;
            r /= i;
        }
    }
    return r;
}


// В какой-то из олимпиадных задач мне потребовалось вычислять много C(n,k) для n >70, т.е. они заведомо не влезали в unsigned long long. Естественно, пришлось использовать «длинную арифметику» (свою). Для этой задачи я написал «рекурсию с памятью»: вычисленные коэффициенты запоминались в массиве и экспоненциального роста времени расчета не было.