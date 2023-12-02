SELECT
    InvoiceDate,
    BillingCity,
    total
FROM
    invoices
WHERE
    InvoiceDate >= '2013-01-01'
    AND total > (
        SELECT
            MAX(Total)
        FROM
            invoices
        WHERE
            InvoiceDate < '2013-01-01'
    );

-------
SELECT
    InvoiceDate,
    BillingCity,
    Total
FROM
    invoices
WHERE
    InvoiceDate <= '2010-01-01'
    AND Total > (
        SELECT
            AVG(Total) AS AvgTotal
        FROM
            invoices
    );