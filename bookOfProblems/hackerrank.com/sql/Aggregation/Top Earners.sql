SELECT
    (salary * months),
    count(employee_id)
FROM
    employee
GROUP BY
    (salary * months)
ORDER BY
    (salary * months) DESC
LIMIT
    1;

--------------------------------------------------------------------------------
SELECT
    max(salary * months),
    count(salary * months)
FROM
    Employee
WHERE
    salary * months IN (
        SELECT
            max(salary * months)
        FROM
            Employee
    );

--------------------------------------------------------------------------------
SELECT
    months * salary AS total,
    count(*)
FROM
    employee
GROUP BY
    total
ORDER BY
    total DESC
LIMIT
    1;