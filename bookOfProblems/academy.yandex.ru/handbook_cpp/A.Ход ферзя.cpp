#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int x1, y1, x2, y2;
    cin >> x1;
    cin >> y1;
    cin >> x2;
    cin >> y2;
    if (x1 == x2 || y1 == y2 || abs(x1 - x2) == abs(y1 - y2)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}

// Для того чтобы определить, может ли ферзь попасть с первой клетки на вторую одним ходом, необходимо проверить, находятся ли эти клетки на одной и той же вертикали, горизонтали или диагонали. Рассмотрим каждый случай подробнее.

//     Если клетки находятся на одной и той же вертикали, то координаты по горизонтали у них будут совпадать: x1 == x2.

//     Если клетки находятся на одной и той же горизонтали, то координаты по вертикали у них будут совпадать: y1 == y2.

//     Если клетки находятся на одной и той же диагонали, то разность координат по горизонтали и вертикали будет равна: abs(x1 - x2) == abs(y1 - y2). Здесь функция abs используется для вычисления модуля разности координат, так как нам нужна только величина разности, а знак не важен.

// Если хотя бы одно из этих условий выполняется, то ферзь может попасть на вторую клетку с первой одним ходом. Если ни одно из условий не выполняется, то ферзь не может сделать такой ход.