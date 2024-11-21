#include <vector>
#include <iostream>

class FenwickTree {
private:
    size_t size;               // Размер дерева (количество элементов + 1)
    std::vector<int64_t> t;    // Дерево (бинарный индексный массив) для хранения сумм

public:
    // Конструктор класса FenwickTree
    FenwickTree(size_t n) : size(n + 1), t(size, 0LL) {}

    // Метод для обновления значения в дереве по индексу
    void update(int index, int64_t delta) {
        ++index;
        for (; index < size; index += (index & -index)) {
            t[index] += delta;
        }
    }

    // Метод для получения суммы элементов до указанного индекса
    int64_t getSum(int index) const {
        ++index;
        int64_t sum = 0;
        for (; index > 0; index -= (index & -index)) {
            sum += t[index];
        }
        return sum;
    }

    // Метод для получения суммы на интервале [left, right] (включая right)
    int64_t getRangeSumClosed(int left, int right) const {
        return getSum(right) - getSum(left - 1);
    }

    // Метод для получения значения элемента по индексу
    int64_t getValue(int index) const {
        return getRangeSumClosed(index, index);
    }

    // Метод для нахождения первого индекса с суммой больше или равной заданному значению
    int findIndexWithSumGreaterOrEqual(int64_t targetSum) const {
        int index = 0;
        int mask = 1 << 20; // Маска для ускоренного двоичного подъема
        while (mask > 0 && index < size - 1) {
            int nextIndex = index + mask;
            if (nextIndex < size && t[nextIndex] < targetSum) {
                targetSum -= t[nextIndex];
                index = nextIndex;
            }
            mask >>= 1;
        }
        return index;
    }

    // Метод для нахождения первого индекса с суммой строго больше заданного значения
    int findIndexWithSumGreater(int64_t targetSum) const {
        int index = findIndexWithSumGreaterOrEqual(targetSum + 1);
        return index;
    }

    // Метод для нахождения последнего индекса с заданным значением
    int findLastIndexWithValue(int64_t value) const {
        int index = findIndexWithSumGreaterOrEqual(value);
        if (index > 0 && getRangeSumClosed(index - 1, index - 1) == value) {
            return index - 1;
        }
        return -1;  // Значение не найдено
    }

    // Метод для инкремента значения элемента по индексу
    void increment(int index, int64_t delta) {
        update(index, delta);
    }

    // Метод для декремента значения элемента по индексу
    void decrement(int index, int64_t delta) {
        update(index, -delta);
    }

    // Метод для очистки дерева (устанавливает все значения в ноль)
    void clear() {
        t.assign(size, 0LL);
    }
};

int main() {
    FenwickTree fenwick(8);

    // Обновляем значения
    fenwick.update(2, 3);
    fenwick.update(4, 5);
    fenwick.update(6, 2);

    // Получаем сумму на интервале [1, 6]
    int64_t sum = fenwick.getRangeSumClosed(1, 6);
    std::cout << "Sum on interval [1, 6]: " << sum << std::endl;

    // Получаем значение элемента по индексу 4
    int64_t valueAtIndex4 = fenwick.getValue(4);
    std::cout << "Value at index 4: " << valueAtIndex4 << std::endl;

    // Находим первый индекс с суммой больше или равной 8
    int indexWithSum8 = fenwick.findIndexWithSumGreaterOrEqual(8);
    std::cout << "First index with sum greater than or equal to 8: " << indexWithSum8 << std::endl;

    // Находим первый индекс с суммой строго больше 8
    int indexWithSumGreater8 = fenwick.findIndexWithSumGreater(8);
    std::cout << "First index with sum greater than 8: " << indexWithSumGreater8 << std::endl;

    // Находим последний индекс с значением 5
    int lastIndexWithValue5 = fenwick.findLastIndexWithValue(5);
    if (lastIndexWithValue5 != -1) {
        std::cout << "Last index with value 5: " << lastIndexWithValue5 << std::endl;
    } else {
        std::cout << "Value 5 not found." << std::endl;
    }

    // Инкрементируем значение по индексу 3
    fenwick.increment(3, 4);

    // Получаем сумму на интервале [2, 7]
    sum = fenwick.getRangeSumClosed(2, 7);
    std::cout << "Sum on interval [2, 7]: " << sum << std::endl;

    // Декрементируем значение по индексу 5
    fenwick.decrement(5, 3);

    // Получаем сумму на интервале [3, 6]
    sum = fenwick.getRangeSumClosed(3, 6);
    std::cout << "Sum on interval [3, 6]: " << sum << std::endl;

    // Очищаем дерево
    fenwick.clear();

    return 0;
}
