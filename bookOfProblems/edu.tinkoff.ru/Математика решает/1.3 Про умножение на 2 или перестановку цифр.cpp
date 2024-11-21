#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

// Функция для проверки, можно ли получить число 86 из данного числа
bool canGet86(int num) {
    // Преобразуем число в строку для удобства манипуляций с цифрами
    std::string numStr = std::to_string(num);
    
    // Переставляем цифры в строке и умножаем на 2
    do {
        int permutedNum = std::stoi(numStr);
        permutedNum *= 2;
        
        // Проверяем, равно ли полученное число 86
        if (permutedNum == 86) {
            return true;
        }
        
        // Переставляем цифры для следующей попытки
    } while (std::next_permutation(numStr.begin(), numStr.end()));
    
    return false;
}

int main() {
    std::vector<int> validNumbers;

    // Перебираем все числа от 1 до 10000 и проверяем, можно ли получить из них 86
    for (int num = 1; num <= 10000; num++) {
        if (canGet86(num)) {
            validNumbers.push_back(num);
        }
    }

    // Выводим найденные числа
    std::cout << "Числа, из которых можно получить 86: ";
    for (int num : validNumbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}