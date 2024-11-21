SELECT
    e.name,
    u.unique_id
FROM
    Employees AS e
    LEFT JOIN EmployeeUNI AS u ON e.id = u.id;

----
SELECT
    unique_id,
    name
FROM
    Employees
    LEFT JOIN EmployeeUNI USING (id);