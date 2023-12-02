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
            AVG(Total)
        FROM
            invoices
    )
ORDER BY
    Total DESC