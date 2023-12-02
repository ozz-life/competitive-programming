-- Выбираем номер и имя студента из информационной таблицы о студентах
SELECT
    stu.roll_number,
    stu.name
FROM
    student_information AS stu
-- Присоединяем таблицу с оценками к информационной таблице по номеру студента
INNER JOIN
    examination_marks AS marks ON stu.roll_number = marks.roll_number
-- Группируем результаты по номеру студента
GROUP BY
    stu.roll_number
-- Фильтруем результаты, оставляя только тех студентов, у которых сумма оценок меньше 100
HAVING
    SUM(marks.subject_one + marks.subject_two + marks.subject_three) < 100;