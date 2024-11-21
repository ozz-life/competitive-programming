-- В условии WHERE дата, как и текст, заключена в одинарные кавычки. При рабо-
-- те с датами используйте те же операторы, что и при работе с числами: =, >, <,
-- BETWEEN и т. д.
SELECT
    InvoiceDate,
    BillingAddress,
    BillingCity,
    Total
FROM
    invoices
WHERE
    InvoiceDate = '2009-01-03 00:00:00'
ORDER BY
    Total;

-- использование функции DATE() позволяет получить результат быстрее, когда
-- параметры времени либо отсутствуют, либо не актуальны
SELECT
    InvoiceDate,
    BillingAddress,
    BillingCity,
    Total
FROM
    invoices
WHERE
    date(InvoiceDate) BETWEEN '2009-01-03'
    AND '2009-12-31'
ORDER BY
    Total;

SELECT
    InvoiceDate,
    BillingAddress,
    BillingCity,
    Total
FROM
    invoices
WHERE
    DATE(InvoiceDate) > '2010-01-02'
    AND Total < 3
ORDER BY
    Total;


-- Десять самых больших счетов после даты
SELECT
    InvoiceDate,
    BillingAddress,
    BillingCity,
    Total
FROM
    invoices
WHERE
    InvoiceDate > '2009-07-05'
ORDER BY
    Total DESC
LIMIT
    10;