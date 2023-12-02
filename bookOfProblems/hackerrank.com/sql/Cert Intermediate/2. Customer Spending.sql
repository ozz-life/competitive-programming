SELECT
    c.customer_name,
    ROUND(SUM(i.total_price), 6)
FROM
    customer c
    INNER JOIN invoice i ON c.id = i.customer_id
GROUP BY
    c.customer_name
HAVING
    SUM(i.total_price) < 0.25 *(
        SELECT
            AVG(total_price)
        FROM
            invoice
    )
ORDER BY
    ROUND(SUM(i.total_price), 6) DESC;
    

    
    
-- Выбираем имя клиента и округленную сумму общей цены его счетов
SELECT
    c.customer_name,
    ROUND(SUM(i.total_price), 6) AS total_price
FROM
    customer AS c
-- Присоединяем таблицу счетов к таблице клиентов по идентификатору клиента
INNER JOIN
    invoice AS i ON c.id = i.customer_id
-- Группируем результаты по имени клиента
GROUP BY
    c.customer_name
-- Фильтруем результаты, оставляя только тех клиентов, у которых общая цена счетов меньше четверти средней общей цены счетов
HAVING
    SUM(i.total_price) < 0.25 * (
        SELECT
            AVG(total_price)
        FROM
            invoice
    )
-- Сортируем результаты по округленной сумме общей цены счетов по убыванию
ORDER BY
    total_price DESC;