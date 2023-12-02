SELECT
    BillingCity,
    AVG(Total) AS [City Average],
    (
        SELECT
            avg(total)
        FROM
            invoices
    ) AS [Global Average]
FROM
    invoices
GROUP BY
    BillingCity
ORDER BY
    BillingCity
    
------------

SELECT
    BillingCity,
    ROUND(AVG(Total), 2) AS [City Average],
    ROUND(
        (
            SELECT AVG(Total)
            FROM invoices
        ),
        2
    ) AS [Global Average]
FROM
    invoices
GROUP BY
    BillingCity
ORDER BY
    BillingCity;