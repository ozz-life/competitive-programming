-- Представления — это виртуальные запросы, созданные с помощью SQL, на
-- которые можно ссылаться в других запросах.
-- Представления создаются посредством добавления в начало запроса следу-
-- ющего условия: CREATE VIEW V_VIEWNAME AS.
-- Представления особенно полезны при написании длинных запросов.


CREATE VIEW V_AvgTotal AS
SELECT
    ROUND(AVG(Total), 2) AS [Average Total]
FROM
    invoices;

----
SELECT
    InvoiceDate,
    BillingAddress,
    BillingCity,
    Total
FROM
    invoices
WHERE
    Total < (
        SELECT
            *
        FROM
            V_AvgTotal
    )
ORDER BY
    Total DESC;

--     ПРИМЕЧАНИЕ
-- Хотя представление — это полноценный SQL-запрос, мы все равно должны
-- ссылаться на него в операторе SELECT, если будем использовать представ-
-- ление вместе с подзапросами. В операторах SELECT можно использовать
-- символ *, чтобы представление, на которое мы ссылаемся, возвращало все
-- строки. В рассматриваемом примере строка только одна — агрегированная
-- сумма.
-- Соединенные представления
CREATE VIEW V_Tracks_InvoiceItems AS
SELECT
    ii.InvoiceId,
    ii.UnitPrice,
    ii.Quantity,
    t.Name,
    t.Composer,
    t.Milliseconds
FROM
    invoice_items ii
    INNER JOIN tracks t ON ii.TrackId = t.TrackId;

CREATE VIEW V_inv_cus_emp AS
SELECT
    i.InvoiceId,
    i.InvoiceDate,
    i.Total,
    i.CustomerId,
    c.FirstName,
    c.LastName,
    c.SupportRepId,
    e.EmployeeId,
    e.LastName,
    e.FirstName,
    e.Title
FROM
    invoices AS i
    INNER JOIN customers AS c ON i.CustomerId = c.CustomerId
    INNER JOIN employees AS e ON e.EmployeeId = c.SupportRepId
ORDER BY
    InvoiceDate;

SELECT
    *
FROM
    V_Tracks_InvoiceItems ii
    INNER JOIN V_inv_cus_emp ice ON ii.InvoiceId = ice.InvoiceId
    
--     ПРИМЕЧАНИЕ
-- Соединенные представления будут работать только в том случае, если
-- ключевые поля, общие для всех этих таблиц, были включены в первона-
-- чальное соединение