-- Выбираем коды акций, у которых цена на завтра больше цены на сегодня
SELECT
    today.stock_code
FROM
    price_today AS today
-- Присоединяем таблицу цен на завтра к таблице цен на сегодня по коду акции
INNER JOIN
    price_tomorrow AS tomorrow ON today.stock_code = tomorrow.stock_code
-- Фильтруем результаты, оставляя только акции, у которых цена на завтра больше цены на сегодня
WHERE
    tomorrow.price > today.price
-- Сортируем результаты по коду акции в возрастающем порядке
ORDER BY
    today.stock_code ASC;