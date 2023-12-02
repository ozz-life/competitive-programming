SELECT
	e.FirstName,
	e.LastName,
	e.EmployeeId,
	c.FirstName,
	c.LastName,
	c.SupportRepId,
	i.CustomerId,
	i.Total
FROM
	invoices AS i
INNER JOIN
	customers AS c
	ON i.CustomerId = c.CustomerId
INNER JOIN
	employees AS e
	ON c.SupportRepId = e.EmployeeId
ORDER BY
	i.Total DESC
LIMIT 10;