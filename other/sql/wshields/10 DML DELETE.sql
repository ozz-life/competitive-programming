-- ПРИМЕЧАНИЕ
-- Как и в случае с UPDATE, не стремитесь сразу выполнять оператор DELETE,
-- сначала напишите оператор SELECT, используя те же таблицы и условие
-- WHERE. Таким образом вы сможете предварительно проанализировать, что
-- вы собираетесь удалить. Как только оператор SELECT вернет ожидаемые
-- записи, вы можете выполнить оператор DELETE.
SELECT
    *
FROM
    employees
WHERE
    EmployeeId = 9;

DELETE FROM
    employees
WHERE
    EmployeeId = 9;

DELETE FROM
    employees
WHERE
    DepartmentId = (
        SELECT
            DepartmentId
        FROM
            departments
        WHERE
            DepartmentName = 'Sales Support Agent'
    );