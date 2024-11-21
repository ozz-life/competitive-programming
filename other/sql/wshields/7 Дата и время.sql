-- STRFTIME(format, timestring, modifier, modifier, ...)
-- Возвращает дату, отформатированную в соответствии
-- со строкой формата, указанной в качестве первого
-- аргумента.
-- Второй параметр используется для упоминания строки
-- времени, за ним следует один или несколько
-- модификаторов (необязательный параметр).
-- 'NOW' Возвращает текущую дату и время. Функция
-- не содержит аргументов.
-- АРГУМЕНТЫ ФУНКЦИИ STRFTIME
-- в определенном порядке: формат, строка времени,
-- модификатор (опционально)
-- (формат ((format))
-- Чувствителен к регистру 
-- '%d'день месяца: 00
-- '%f'доли секунды: SS.SSS
-- '%H'час: 00-24
-- '%j'день года: 001-366
-- '%J'юлианская дата
-- '%m'месяц: 01-12
-- '%M'минута: 00-59
-- '%s'количество секунд с 1 января 1970 года
-- '%S'секунда: 00-59
-- '%w'день недели: 0–6 (воскресенье = 0)
-- '%W'неделя года: 00-53
-- '%Y'годы: 0000-9999
-- (строка времени (timestring))
-- 'YYYY-MM-DD'Формат даты: Год-Месяц-День
-- 'now'Текущие дата и время
-- 'DATETIME' полеПоле базы данных в формате даты и/или времени
-- '+ X days'Где Х — количество дней, добавляемых
-- к результату
-- '+ X months'Где Х — количество месяцев, добавляемых
-- к результату
-- '+ X years'Где Х — количество лет, добавляемых
-- к результату
-- '- X days'/months/yearsГде Х — количество дней/месяцев/лет,
-- вычитаемых из результата
-- 'start of day'Сдвиг времени на начало дня
-- 'start of month'Сдвиг даты на начало месяца
-- 'start of year'Сдвиг даты на начало года
SELECT
    STRFTIME(
        'The Year is: %Y The Day is: %d The Month is %m',
        '2011-05-22'
    ) AS [Text with Conversion Specifications];

-- НАПОМИНАНИЕ
-- Спецификация в функции преобразования всегда начинается с символа %,
-- за которым следует чувствительный к регистру буквенный символ. Исполь-
-- зование, например, %M (верхний регистр) вместо %m даст нам минуты
-- вместо месяцев.
SELECT
    LastName,
    FirstName,
    STRFTIME('%Y-%m-%d', BirthDate) AS [Birthday No Timecode],
    STRFTIME('%Y-%m-%d', 'now') - STRFTIME('%Y-%m-%d', BirthDate) AS [Age]
FROM
    employees
ORDER BY
    Age;
    
SELECT
    FirstName,
    LastName,
    BirthDate AS [Birthday],
    STRFTIME('%Y-%m-%d', 'now') - STRFTIME('%Y-%m-%d', HireDate) AS [Years of Service]
FROM
    employees
ORDER BY
    [Years of Service] DESC