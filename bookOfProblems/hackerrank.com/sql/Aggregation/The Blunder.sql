SELECT
    ceil(avg(salary) - avg(REPLACE(salary, 0, '')))
FROM
    EMPLOYEES
    
--------------------------------------------------------------------------------