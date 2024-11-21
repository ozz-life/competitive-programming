#ifndef __FENWICK_HPP__
#define __FENWICK_HPP__

#include <bits/stdc++.h>

class FenwickTree {
private:
  std::size_t size; // Размер дерева (количество элементов + 1)
  std::vector<int64_t>
      t; // Дерево (бинарный индексный массив) для хранения сумм
  std::vector<int64_t> values; // Дополнительный массив для хранения фактических
                               // значений элементов

public:
  /**
   * Конструктор класса FenwickTree.
   * @param n Размер дерева (количество элементов).
   */
  FenwickTree(std::size_t n) : size(n + 1), t(size, 0LL), values(size, 0LL) {}

  /**
   * Обновляет значение в дереве по индексу.
   * @param index Индекс, который нужно обновить.
   * @param delta Изменение значения.
   */
  void update_tree_index(int index, int64_t delta) {
    for (; (std::size_t)index < size; index += index & -index) {
      t[index] += delta;
    }
  }

  /**
   * Обновляет значение элемента по индексу.
   * @param index Индекс элемента.
   * @param value Новое значение элемента.
   */
  void update_value(std::size_t index, int64_t value) {
    int64_t delta = value - values[index + 1];
    increase_value(index, delta);
  }

  /**
   * Увеличивает значение элемента по индексу на заданную величину.
   * @param index Индекс элемента.
   * @param delta Изменение значения элемента.
   */
  void increase_value(std::size_t index, int64_t delta) {
    ++index;
    values[index] += delta;

    update_tree_index(index, delta);
  }

  /**
   * Возвращает сумму элементов до указанного индекса.
   * @param index Индекс элемента.
   * @return Сумма элементов до указанного индекса.
   */
  int64_t get_prefix_sum(int index) {
    ++index;

    int64_t sum = 0;
    for (; index > 0; index -= index & -index) {
      sum += t[index];
    }

    return sum;
  }

  /**
   * Возвращает максимальный префикс, который не превышает заданное значение.
   * @param value Значение для сравнения.
   * @return Пара: индекс максимального префикса и сумма элементов до этого
   * индекса.
   */
  std::pair<std::size_t, int64_t> get_max_prefix_lower(int64_t value) {
    std::size_t result = 0;
    int64_t sum = 0;

    for (int bit = 20; bit >= 0; --bit) {
      std::size_t next = result | (1 << bit);
      if (next < size && sum + t[next] < value) {
        result = next;
        sum += t[next];
      }
    }

    return {result, sum};
  }

  /**
   * Очищает дерево (устанавливает все значения в ноль).
   */
  void clear() {
    t.assign(size, 0LL);
    values.assign(size, 0LL);
  }
};

////////////////////////////////////////////////////////////////////////////////
//Интеграция целиком

#include <vector>

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
    int64_t getSum(int index) {
        ++index;
        int64_t sum = 0;
        for (; index > 0; index -= (index & -index)) {
            sum += t[index];
        }
        return sum;
    }

    // Метод для получения суммы на интервале [left, right]
    int64_t getRangeSum(int left, int right) {
        if (left > 0) {
            return getSum(right) - getSum(left - 1);
        } else {
            return getSum(right);
        }
    }

    // Метод для очистки дерева (устанавливает все значения в ноль)
    void clear() {
        t.assign(size, 0LL);
    }
};


#include <iostream>

int main() {
    FenwickTree fenwick(5);

    // Обновляем значения
    fenwick.update(2, 3);
    fenwick.update(4, 5);

    // Получаем сумму на интервале [1, 4]
    int64_t sum = fenwick.getRangeSum(1, 4);
    std::cout << "Sum on interval [1, 4]: " << sum << std::endl;

    // Обновляем еще значения
    fenwick.update(3, 2);
    fenwick.update(5, 1);

    // Получаем сумму на интервале [2, 5]
    sum = fenwick.getRangeSum(2, 5);
    std::cout << "Sum on interval [2, 5]: " << sum << std::endl;

    // Очищаем дерево
    fenwick.clear();

    return 0;
}

#endif // __FENWICK_HPP__