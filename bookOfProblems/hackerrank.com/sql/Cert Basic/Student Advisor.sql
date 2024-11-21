SELECT roll_number,name
FROM student_information a
INNER JOIN faculty_information b
ON a.advisor = b.employee_ID
WHERE (b.gender = 'M' and b.salary>15000) or (b.gender = 'F' and b.salary>20000);

--------------------------------------------------------------------------------

-- Выбираем номер и имя студента
SELECT
    a.roll_number,
    a.name
FROM
    student_information AS a
-- Присоединяем таблицу информации о факультете к таблице информации о студентах по идентификатору руководителя
INNER JOIN
    faculty_information AS b
ON
    a.advisor = b.employee_ID
-- Фильтруем результаты, оставляя только студентов, у которых руководитель мужского пола с зарплатой более 15000 или женского пола с зарплатой более 20000
WHERE
    (b.gender = 'M' AND b.salary > 15000)
    OR
    (b.gender = 'F' AND b.salary > 20000);