SELECT
    BillingCountry,
    BillingCity,
    AVG(Total)
FROM
    invoices
GROUP BY
    BillingCountry,
    BillingCity
ORDER BY
    BillingCountry