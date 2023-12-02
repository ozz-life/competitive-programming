SELECT
    i.InvoiceId,
    c.CustomerId,
    c.FirstName,
    c.Address,
    i.InvoiceDate,
    i.BillingAddress,
    i.Total
FROM
    invoices AS i
    LEFT OUTER JOIN customers AS c ON i.CustomerId = c.CustomerId;

-- ПРИМЕЧАНИЕ
-- Слово «внешнее» (OUTER) необязательно.
-- ПРИМЕЧАНИЕ
-- Ключевое слово «внешнее» (OUTER) необязательно. Вариант RIGHT JOIN
-- дает тот же результат.
SELECT
    i.InvoiceId,
    c.CustomerId,
    c.Name,
    c.Address,
    i.InvoiceDate,
    i.BillingAddress,
    i.Total
FROM
    invoices AS i
    RIGHT OUTER JOIN customers AS c ON i.CustomerId = c.CustomerId