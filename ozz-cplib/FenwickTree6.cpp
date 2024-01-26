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

    // Метод для нахождения k-го по порядку элемента в отсортированном списке
    int findKthElement(int k) const {
        int index = 0;
        int mask = 1 << 20; // Маска для ускоренного двоичного подъема
        while (mask > 0 && index < size - 1) {
            int nextIndex = index + mask;
            if (nextIndex < size && t[nextIndex] < k) {
                k -= t[nextIndex];
                index = nextIndex;
            }
            mask >>= 1;
        }
        return index;
    }

    // Метод для нахождения порядкового номера элемента в отсортированном списке
    int findOrderOfElement(int index) const {
        return getSum(index - 1) + 1;
    }

    // Метод для инкремента значения элемента по индексу
    void increment(int index, int64_t delta) {
        update(index, delta);
    }

    // Метод для декремента значения элемента по индексу
    void decrement(int index, int64_t delta) {
        update(index, -delta);
    }

    // Метод для прибавления значения ко всем элементам в интервале [left, right]
    void addRange(int left, int right, int64_t delta) {
        update(left, delta);
        update(right + 1, -delta);
    }

    // Метод для нахождения префиксной суммы до указанного индекса
    int64_t getPrefixSum(int index) const {
        return getSum(index);
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

    // Прибавляем значение 4 ко всем элементам в интервале [2, 5]
    fenwick.addRange(2, 5, 4);

    // Получаем сумму на интервале [1, 6] после прибавления
    sum = fenwick.getRangeSumClosed(1, 6);
    std::cout << "Sum on interval [1, 6] after adding range: " << sum << std::endl;

    // Получаем префиксную сумму до индекса 4
    int64_t prefixSum = fenwick.getPrefixSum(4);
    std::cout << "Prefix sum until index 4: " << prefixSum << std::endl;

    // Очищаем дерево
    fenwick.clear();

    return 0;
}
