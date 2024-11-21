SELECT
    *
FROM
    my_contacts
WHERE
    first_name = 'ann';

-- Экранирование апострофа через '' или \'
SELECT
    location,
    TYPE
FROM
    doughnut_ratings
WHERE
    rating = 10
    AND TYPE = 'с глазурью';

--- Сравнение в алфавитном порядке
SELECT
    drink_name
FROM
    drink_info
WHERE
    drink_name >= 'Г'
    AND drink_name < 'Д';

-- Поиск NULL
SELECT
    drink_name
FROM
    drink_info
WHERE
    calories IS NULL;

-- Поиск по городам Калифорнии
-- % - любое количество неизвестных символов
-- _ - Ровно один проивольный символ
SELECT
    *
FROM
    my_contacts
WHERE
    location LIKE '%CA'
    AND first_name LIKE '_им';

-- Диапазон больше или равно
SELECT
    drink_name
FROM
    drink_info
WHERE
    calories BETWEEN 30
    AND 60;

--     Попробуйте использовать BETWEEN с текстовыми столбцами. Напишите запрос, который
-- возвращает названия всех напитков, начинающиеся с букв от «Д» до «О».
-- Чтобы не строить много OR используем IN
SELECT
    date_name
FROM
    black_book
WHERE
    rating IN(
        'оригинально',
        'потрясающе',
        'неплохо',
        'восхитительно'
    );

-- Всё, кроме
SELECT
    date_name
FROM
    black_book
WHERE
    rating NOT IN(
        'оригинально',
        'потрясающе',
        'неплохо',
        'восхитительно'
    );

-- ПОМНИТЬ, что NOT следует сразу ж е после WHERE.
-- Используется с AND OR, но после WHERE
-- При использовании с AND и OR ключевое слово NOT ставит­ся после них:
SELECT
    date_name
FROM
    black_book
WHERE
    NOT date_name LIKE 'A%'
    AND NOT date_name LIKE 'B%';