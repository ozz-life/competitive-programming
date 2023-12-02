-- узнать, получены ли какие-либо другие счета после указанно-
-- го выше счета, мы добавим подзапрос, заключенный в круглые скобки, а затем
-- добавим внешний запрос.
SELECT
    InvoiceDate,
    BillingAddress,
    BillingCity
FROM
    invoices
WHERE
    InvoiceDate > (
        SELECT
            InvoiceDate
        FROM
            invoices
        WHERE
            InvoiceId = 251
    )