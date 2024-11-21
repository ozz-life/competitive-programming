#include <iostream>
using namespace std;
int main() {
  int a, b, n;
  cin >> a >> b >> n;

  a = a * n;
  b = b * n;
  cout << a + b / 100 << ' ' << b % 100;

  // или

  int total = ((a * 100) + b) * n;
  cout << total / 100 << ' ' << total % 100;

  return 0;
}

// Тут есть два актуальных решения, не прибегая к дополнительным материалам
// которые вы не изучали) 1) это переводить рубли в копейки и считать стоимость
// в копейках, а потом выводить. 2) это переводить копейки в рубли .... и т.д.
// P.S. решил обеими вариантами)
// к примеру микро подсказка: a * 100 + b - это стоимость пирожка только в
// копейках)

// 1 руб = 100 коп! Используйте свойство С ++ по округлению, т.е. / 100 для
// приведения копеек в рубли. Тогда 230 / 100 после округления в меньшую сторону
// будет 2.   А так же    % 100 для копеек. Тогда 230 коп. превращаются  в 30
// коп. 200 в 00 коп.. И снова можно решить просто в одну строчку cout. << (для
// рублей) 1) Умножаем количество рублей (a) на количество пирожков (n) 2)
// прибавляем количество копеек (b) умноженное на количество пирожков (n) и
// разделенное на 100 (так как в рубле 100 копеек и чтобы прибавлять рубли к
// рублям, а не рубли к копейкам. << "(обязательно пробел  между верхними
// двойными кавычками)" <<  (для копеек) 1) умножаем копейки (b) на пирожки (n)
// и используем % 100 (используем оператор остатка %, т.е. убираем все, что
// относится к сотням, которые уже учтены в разделе "для рублей" . Оставляем
// десятки. Если 200 - то станет 00, если 230 или 30, то оставит только 30 так
// как сотни уберет). При необходимости перечитываем абзац до 50 раз ))))

// Программирование, это, как магия! Абсолютно нелогично и запутанно с точки
// зрения человека, зато с точки зрения машины, работает безупречно! Как пример,
// даны рубли, копейки и число желаемых пирожков, надо рассчитать к-во
// необходимых денег для покупки в рублях и копейках. Как же это сделать?
// Правильно! Применяем чертову логику, множим число рублей на 100 и получаем
// копейки, потом складываем всё это добро в огромную вонючую кучу и перемножаем
// ее на количество желаемых пирожков. Ура, теперь делим кучу на 100 и получаем
// рубли, а чтобы получить копейки нужно посчитать остаток от деления второй,
// непонятно откуда взявшейся, кучи. Готово! У нас на руках 2 переменные,
// которые надо выводить. Откуда вторая куча взялась я даже спрашивать боюсь, но
// тем и забавно программирование, иногда нужно обратиться к черту или еще к
// кому похуже чтобы получить решение.