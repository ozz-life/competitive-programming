#include <iostream>

int main() {
    int number = 1;  // начнем с 1 и будем увеличивать число, пока не найдем подходящее
    int result = 0;  // для хранения результата вычислений

    while (true) {
        result = ((number - 5) / 2 + 6) * 9;
        result = result / 10;

        if (result == 7) {
            std::cout << "Лёня задумал число: " << number << std::endl;
            break;
        }

        number++;
    }

    return 0;
}