SELECT
    c.company_code,
    c.founder,
    count(DISTINCT lm.lead_manager_code) AS lead_managers_count,
    count(DISTINCT sm.senior_manager_code) AS senior_managers_count,
    count(DISTINCT m.manager_code) AS managers_count,
    count(DISTINCT e.employee_code) AS employees_count
FROM
    Company AS c
    INNER JOIN Lead_Manager AS lm ON c.company_code = lm.company_code
    INNER JOIN Senior_Manager AS sm ON sm.company_code = c.company_code
    INNER JOIN Manager AS m ON m.company_code = c.company_code
    INNER JOIN Employee AS e ON e.company_code = c.company_code
GROUP BY
    c.company_code,
    c.founder
ORDER BY
    c.company_code ASC;