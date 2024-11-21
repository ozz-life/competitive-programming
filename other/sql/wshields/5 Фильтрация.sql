-- ПРИМЕЧАНИЕ
-- Условие WHERE всегда следует после условия FROM, но всегда находится
-- перед ORDER BY. В приведенном выше примере условие WHERE добавлено
-- для возврата всех счетов на сумму $1,98. Знак = это оператор сравнения.
SELECT
    InvoiceDate,
    BillingAddress,
    BillingCity,
    Total
FROM
    invoices
WHERE
    Total = 1.98
ORDER BY
    InvoiceDate;

-- Рассмотрим следующий запрос, который возвращает счета, находящиеся в диа-
-- пазоне от $1,98 до $5,00.
SELECT
    InvoiceDate,
    BillingAddress,
    BillingCity,
    Total
FROM
    invoices
WHERE
    Total BETWEEN 1.98
    AND 5.00
ORDER BY
    InvoiceDate;

-- Следующий запрос возвращает только
-- суммы счетов-фактур, равные $1,98 или $3,96 (рис. 47).
-- ПРИМЕЧАНИЕ
-- С помощью оператора = мы можем добавить только одно значение. С по-
-- мощью оператора IN мы можем добавить сколько угодно значений, раз-
-- деленных запятыми. Также мы можем использовать оператор IN с текстом
-- (описано в следующем разделе).
SELECT
    InvoiceDate,
    BillingAddress,
    BillingCity,
    Total
FROM
    invoices
WHERE
    Total IN (1.98, 3.96)
ORDER BY
    InvoiceDate;

-- сколько счетов было выставлено в городе Тусон (Tucson)?
-- ПРИМЕЧАНИЕ
-- При использовании текста в качестве критерия в условии WHERE указан-
-- ные текстовые значения должны быть заключены в одинарные кавычки
-- (BillingCity = 'Tucson').
SELECT
    InvoiceDate,
    BillingAddress,
    BillingCity,
    Total
FROM
    invoices
WHERE
    BillingCity = 'Tucson'
ORDER BY
    Total;

-- IN множество
SELECT
    InvoiceDate,
    BillingAddress,
    BillingCity,
    Total
FROM
    invoices
WHERE
    BillingCity IN ('Tucson', 'Paris', 'London')
ORDER BY
    Total;

-- 'T%'Находит все записи, начинающиеся сбуквы T
-- '%T'Находит все записи, заканчивающиеся буквой T
-- '%T%'Находит все записи, содержащие в строке букву T
-- 'T%T'Находит все записи, начинающиеся и заканчивающиеся буквой T

--Города заканчивающиеся на t
SELECT
    InvoiceDate,
    BillingAddress,
    BillingCity,
    Total
FROM
    invoices
WHERE
    BillingCity LIKE '%T'
ORDER BY
    Total;
    
-- Не имеют т в названии
SELECT
InvoiceDate,
BillingAddress,
BillingCity,
Total
FROM
invoices
WHERE
BillingCity NOT LIKE '%T%'
ORDER BY
Total