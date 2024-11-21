SELECT COUNT(*) AS CountOfCustomersWithoutPostalCode
FROM Customers
WHERE PostalCode IS NULL OR PostalCode = ''
