SELECT
    t1.customer_id,
    t1.name,
    concat("+", t2.country_code, t1.phone_number) AS country_code
FROM
    customers AS t1
    LEFT JOIN country_codes AS t2 ON t1.country = t2.country;

--------------------------------------------------------------------------------
SELECT
    a.customer_id,
    a.name,
    concat("+", b.country_code, a.phone_number)
FROM
    customers AS a
    LEFT JOIN country_codes AS b ON a.country = b.country
ORDER BY
    a.customer_id;
    
--------------------------------------------------------------------------------

-- Выбираем идентификатор клиента, имя клиента и номер телефона с добавленным кодом страны
SELECT
    a.customer_id,
    a.name,
    CONCAT("+", b.country_code, a.phone_number) AS full_phone_number
FROM
    customers AS a
-- Присоединяем таблицу кодов стран к таблице клиентов по коду страны
LEFT JOIN
    country_codes AS b ON a.country = b.country
-- Сортируем результаты по идентификатору клиента
ORDER BY
    a.customer_id;