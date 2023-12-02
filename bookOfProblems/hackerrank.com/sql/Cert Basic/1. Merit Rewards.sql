SELECT
    t1.employee_ID,
    t1.name
FROM
    (
        SELECT
            employee_ID,
            name
        FROM
            employee_information
        WHERE
            division = 'HR'
    ) AS t1
    LEFT JOIN last_quarter_bonus AS t2 ON t1.employee_ID = t2.employee_ID
WHERE
    t2.bonus >= 5000;

--------------------------------------------------------------------------------
SELECT
    ei.employee_ID,
    ei.name
FROM
    employee_information ei
    JOIN last_quarter_bonus b ON b.employee_ID = ei.employee_ID
WHERE
    ei.division LIKE 'HR'
    AND b.bonus >= 5000;
    
--------------------------------------------------------------------------------

-- Выбираем идентификатор и имя сотрудника из таблицы информации о сотрудниках
SELECT
    ei.employee_ID,
    ei.name
FROM
    employee_information AS ei
-- Присоединяем таблицу с последними бонусами к таблице информации о сотрудниках по идентификатору сотрудника
JOIN
    last_quarter_bonus AS b ON b.employee_ID = ei.employee_ID
-- Фильтруем результаты, оставляя только сотрудников из отдела HR с бонусами не менее 5000
WHERE
    ei.division LIKE 'HR'
    AND b.bonus >= 5000;