-- ОПЕРАТОРЫ СРАВНЕНИЯ
-- = Равно
-- >= Больше или равноOR (Или)
-- > Больше, чем
-- < Меньше, чем
-- <= Меньше или равно
-- <> Не равно

-- ЛОГИЧЕСКИЕ ОПЕРАТОРЫ

-- BETWEEN (Между)
-- IN (В)
-- LIKE (Как)
-- AND (И)
-- OR (Или)

-- АРИФМЕТИЧЕСКИЕ ОПЕРАТОРЫ
-- + Сложение
-- - Вычитание
-- / Деление
-- * Умножение
-- % Остаток от деления

SELECT
    Total AS [Original Amount],
    Total + 10 AS [Addition Operator],
    Total - 10 AS [Subtraction Operator],
    Total / 10 AS [Division Operator],
    Total * 10 AS [Multiplication Operator],
    Total % 10 AS [Modulo Operator]
FROM
    invoices
ORDER BY
    Total DESC
    
;

SELECT
    Total AS [Original Amount],
    Total * 1.15 AS [Total with 15% Tax]
FROM
    invoices
ORDER BY
    Total DESC;
