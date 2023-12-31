#include <iostream>
using namespace std;
int main() {
  int n, b;
  cin >> n;
  cout << (n / 2 + 1) * 2;
  //   OR
  //   cout << (n / 2 * 2 ) + 2;
}

// Если без условных операторов, то решается тяни-толкаем (иначе говоря,
// возвратно-поступательно). Сначала — шаг отступления, потом — шаг вперёд.

// Пояснение: всё множество целых чисел можно сгруппировать в пары из соседних
// так, что меньшее будет чётным, большее — нечётным. Разница чисел в каждой
// паре составляет 1. Например, 44 и 45. Таким образом любое целое число
// окажется из такой пары. Тяни-толкай позволит независимо от чётности числа
// свести его к чётному в той же паре. Вот как это делается: \(x\ /\ 2\ * 2\)

// 44 / 2 == 22 и 45 / 2 == 22. Число 22 не зависит от выбора числа в паре
// 44, 45. А если следующим шагом умножить 22 на 2, то получим 44. То есть и 44
// ⇒44, и 45 ⇒44. Догадались, как теперь получить следующее чётное число?

// Уххх, минут 15 думал... И то, пришлось прибегнуть к "подглядке" в комменты.
// Совет для решающих: необходимо воспользоваться оператором "/". Подумайте, как
// можно используя отброс остатка при делении, найти универсальное решение для
// четных и нечетных чисел. Дерзайте, и не сдавайтесь! Хорошая тренировка для
// ума :)

// 1. Ввести можно как чётное так и нечетное число n. Чётное делится целиком 2,
// нечетное с остатком. Например, 3/2 = 1,5. В программе останется в
// остатке 1. 2. Что нужно сделать, чтобы получить 4 ( следующее чётное число
// после введенной "3"? Умножить на 2 и прибавить 2 1*2+2= 4 И так с любым
// числом. А в программе это выглядит так: k=n / 2 * 2 + 2 Надеюсь, что кому-то
// будет полезно :)

// Не забывайте что простое деление пишется целым числом, никак не округляя
// остаток. То есть 7/2 будет равно 3. Число нужно всего лишь поделить на два, а
// затем умножить на два и прибавить двойку. Если число изначально было четным,
// то после деления и умножения не изменится и прибавив 2 получим следующее
// четное. А если изначальное число было нечетным, то после деления и умножения
// на два, станет четным на единицу меньше, после чего снова прибавляем 2

// для вычисления следующего четного числа, которое больше или равно заданному
// числу n. Эта формула основана на свойстве четных чисел, которые имеют разницу
// между соседними четными числами в 2. Таким образом, если вы хотите найти
// следующее четное число после n, вы можете использовать эту формулу:

// next_even = (n / 2 + 1) * 2;

// Где n - заданное число, а next_even - следующее четное число после n.

// Пример:
// Если n равно 7:

//     (7 / 2) + 1 = 3 + 1 = 4
//     4 * 2 = 8

// Таким образом, следующее четное число после 7 будет 8.