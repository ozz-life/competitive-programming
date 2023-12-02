SELECT
    InvoiceDate
FROM
    invoices
WHERE
    InvoiceId IN (251, 252, 255);

---
SELECT
    InvoiceDate,
    BillingAddress,
    BillingCity
FROM
    invoices
WHERE
    InvoiceDate IN (
        SELECT
            InvoiceDate
        FROM
            invoices
        WHERE
            InvoiceId IN (251, 252, 255)
    )