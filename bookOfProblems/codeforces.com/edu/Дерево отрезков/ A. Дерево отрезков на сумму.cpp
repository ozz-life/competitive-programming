// не работает

#include <bits/stdc++.h>

struct segtree {
  std::vector<int64_t> tree;
  int size;

  // Процедура создаёт дерево отрезков. Просто дополняет массив нулями до
  // степени двойки и создаёт массив нужного размера
  void init(int n) {
    size = 1;
    while (size < n)
      size *= 2;
    tree.assign(2 * size - 1, 0);
  }

  void build(std::vector<int> &a, int x, int lx, int rx) {
    // Если мы дошли до нижнего уровня
    if (rx - lx == 1) {
      if (lx < a.size())
        tree[x] = a[lx];
    } else {
      int m = (lx + rx) / 2;
      build(a, 2 * x + 1, lx, m);
      build(a, 2 * x + 2, m, rx);
      tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }
  }

  void build(std::vector<int> &a) {
    init(a.size());
    build(a, 0, 0, size);
  }

  // Процедура рекурсивно идёт вглубь дерева и на выходе пересчитывает значения
  void set(int i, int v, int x, int lx, int rx) {
    if (rx - lx == 1) {
      tree[x] = v;
      return;
    }
    int m = (lx + rx) / 2;
    if (i < m) { // рекурсивно в левое поддерво
      set(i, v, 2 * x + 1, lx, m);
    } else { // рекурсивно в правое поддерево
      set(i, v, 2 * x + 2, m, rx);
    }
    // на выходе из рекурсии пересчитывает все значения узла
    tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
  }

  void set(int i, int v) { set(i, v, 0, 0, size); }

  // Рекурсивная процедура, которая обходит дерево с нужными отсечениями и
  // считает суммы элементов, которые нам нужны
  int64_t sum(int l, int r, int x, int lx, int rx) {
    // Если мы целиком снаружи значит два отрезка не пересекаются
    if (l >= rx || lx >= r) {
      return 0;
    }
    // Если мы целиком внутри, отрезки вкладываются, значит все отрезки в
    // поддереве хорошие и нужно вернуть их сумму
    if (l >= rx && rx <= r) {
      return tree[x];
    }
    // Иначе делаем два рекурсивных запуска и возвращаем их сумму
    int m = (lx + rx) / 2;
    // посчитаем сумму в левой половине
    int64_t s1 = sum(l, r, 2 * x + 1, lx, m);
    // посчитаем сумму в правой половине
    int64_t s2 = sum(l, r, 2 * x + 2, m, rx);
    return s1 + s2;
  }

  int64_t sum(int l, int r) { return sum(l, r, 0, 0, size); }
};

int main() {

  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i)
    std::cin >> a[i];

  segtree st;
  st.build(a);

  for (int t = 0; t < m; ++t) {
    int c;
    std::cin >> c;
    if (c == 1) {
      int i, v;
      std::cin >> i >> v;
      st.set(i, v);
    } else {
      int l, r;
      std::cin >> l >> r;
      std::cout << st.sum(l, r) << "\n";
    }
  }

  return 0;
}