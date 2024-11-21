#include <iostream>

using namespace std;

int main() {
  int N, H, M, m, S, s;
  cin >> N;
  H = N / 3600 % 24;
  M = N % 3600 / 60 / 10;
  m = N % 3600 / 60 % 10;
  S = N % 3600 % 60 / 10;
  s = N % 3600 % 60 % 10;
  cout << H << ":" << M << m << ":" << S << s;
}

// На примере этой задачи можно продемострировать два любопытных свойство
// оператора %. Для этого давайте посмотрим как выглядит арифметическое
// выражение для выделения цифры  разряда единиц для секунд из общего числа
// секунд n:

// n % 60 % 10

// Остаток от деления на 60 даёт секунды, а остаток от деления на 10 выделяет
// цифру младшего разряда.

// Оказывается, формула

// n % 10

// даёт точно такой же результат! Такое возможно только в случае, когда делитель
// слева кратен делителю справа!  В общем виде:

// (1) n % d % d1 = n % d1​ - делители слева
// направо и выполняется d % d1 = 0 (доказательство во вложенном
// комментарии).

// Точно так же сокращается арифметическое выражение вычисляющее младшую цифру
// для минут:

// n / 60 % 60 % 10 = n / 60 % 10

// Продолжим сокращать число операций пользуясь уже другим, не менее интересным
// свойством.  На этот раз возьмём выражение выделяущее десятки из минут:

// n / 60 % 60 / 10 = n % 3600 / 60 / 10 = n % 3600 / 600

// В приципе первое преобразование поддаётся простому логическому объяснению.
// Если посмотреть на исходную формулу, то в ней минуты из общего количества
// секунд nn можно выделить поделитв сначала на 6060. Но полученное число
// n / 60 будет содержать не только сами минуты, но и часы и даже сутки
// выраженные в минутах. Чтобы отсечь последние нужно взять остаток от деления
// на 60. Но можно поступить иначе. Выполнив n % 3600 мы получаем секунды
// без учёта часов и суток, только минуты и секунды выраженные в секундах.
// Теперь остаётся лишь узнать сколько в полученном числе минут, разделив его на
// 60:

// n % 3600 / 60

// Эти два способа выделить разряд числа выполняются для всех систем счистления!
// Но можно взглянуть на это преобразование вне контекста систем счисления.
// Давайте ещё раз  взглянем на равенство:

// n / 60 % 60 = n % 3600 / 60

// Мы тут как бы поменяли местами операции / и % и при этом в конечном выражении
// делители при операторе взятия остатка как бы перемножились:

// n / 60 % 60 = n % (60 * 60) / 60

// Оказывается существует общая формула для таких преобразований (доказательство
// во вложенном комментарии):

// (2) n / d % d1 = n % (d1 * d) / d

// которую, кстати можно применять и в обратном направлении, например, возьмём
// выражение для десятков секунд (я это преобразование в решение не включил,
// потому что оно не уменьшает число матем. операций, а лишь уменьшает сами
// делители):

// n % 60 / 10 = n % (6∗10) / 10 = n / 10 % 6

// Или, например, в некоторых решениях выражение для количества часов выглядит
// так:

// n % 86400 / 3600

// Откуда оно взялось? Оказывается оно равно

// n / 3600 % 24

// Ну тут конечно можно было бы оперется на ту же логику что мы применяли ранее
// для минут и сказать что n % 86400 отделяет количество секунд в рамках
// одних суток, потому что 86400 = 24 ∗ 3600 - количество секунд в
// сутках! Но можно сразу применить общую формулу (2) в обратном направлении:

// n % 86400 / 3600 = n % (24∗3600) / 3600 = n / 3600 % 24

#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  cout << n / 3600 % 24 << ":" << n % 3600 / 600 << n / 60 % 10 << ":"
       << n % 60 / 10 << n % 10;
  return 0;
}

// https://stepik.org/lesson/13021/step/12?thread=solutions&unit=4362

// 1. Итак,  докажем

// (1) n%d%d1=n%d1(1) n%d%d1​=n%d1​, где dd, d1d1​ - делители слева
// направо и выполняется d%d1=0d%d1​=0

// Первое деление с остатком можно записать математически в общем виде:

// n=q∗d+rn=q∗d+r, где qq-частное, rr-остаток.

// Если теперь остаток rr поделить на  d2d2​
// получим:

// r=q1∗d1+r1r=q1​∗d1​+r1​

// Теперь восопользуемся ключевым условием о том, что dd кратно d1d1​, а это
// математически записывается так:

// d=k∗d1d=k∗d1​, где kk-некоторое натуральное
// число

// Получили систему трёх уравнений:

// {n=q∗d+rr=q1∗d1+r1d=k∗d1⎩
// ⎨

// ⎧​n=q∗d+rr=q1​∗d1​+r1​d=k∗d1​​

// Подставим второе уравнение в первое вместо rr:

// n=q∗d+q1∗d1+r1n=q∗d+q1​∗d1​+r1​

// Подставим в полученное уравнение третье уравнение из системы вместо dd:

// n=q∗k∗d1+q1∗d1+r1=(q∗k+q1)∗d1+r1n=q∗k∗d1​+q1​∗d1​+r1​=(q∗k+q1​)∗d1​+r1​

// А это, по определению, означает что n%d1=r1n%d1​=r1​. Что и требовалось
// доказать!

// 2. Докажем

// (2) n/d%d1=n%(d1∗d)/d(2) n/d%d1​=n%(d1​∗d)/d, где dd, d1d1​ - делители
// слева направо

// матем. смысл выражения слева можно записать в виде следующей системы
// уравнений:

// {n=d∗k+rk=d1∗k1+r1{n=d∗k+rk=d1​∗k1​+r1​​

// где r1r1​ и есть результат всего выражения слева! Подставим kk из второго
// уравнения в первое:

// n=d1∗d∗k1+d∗r1+rn=d1​∗d∗k1​+d∗r1​+r

// Теперь перенесём слагаемое d∗d1∗k1d∗d1​∗k1 в левую сторону
// уравнения:

// n−d1∗d∗k1=d∗r1+rn−d1​∗d∗k1​=d∗r1​+r

// На первый взгляд тут ничего не понятно ). Но если приглядется, то выражение
// слева - это запись остатка от деления на число d∗d1d∗d1​! Действительно,
// давайте введём переменную r3r3​ следующим
// образом:

// n−d1∗d∗k1=r3=d∗r1+rn−d1​∗d∗k1​=r3​=d∗r1​+r

// Тогда отсюда получается:

// n=d1∗d∗k1+r3n=d1​∗d∗k1​+r3​

// Другими словами, при делении числа dd на число d∗d1d∗d1​ получается остаток
// r3r3​!

// Тогда, что означает уравнение:

// r3=d∗r1+rr3​=d∗r1​+r

// Оно означает что при целочисленном делении числа r3r3​ на dd получается
// число r1r1​! Легко заметить, что два последних уравнения описывают операции
// выполняемые выражением справа

// n%(d1∗d)/dn%(d1​∗d)/d

// и они дают результат r1r1​. Но ранее мы определили переменную r1r1​ как
// значение выражения слева. Значит выражения слева и справа в уравнении (2)
// совпадают! Что и требовалось доказать.