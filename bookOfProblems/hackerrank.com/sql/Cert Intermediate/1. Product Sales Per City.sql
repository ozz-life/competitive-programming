 -- Выбираем название города, название продукта и округленную сумму общей цены по продукту
SELECT
    ci.city_name,
    pr.product_name,
    ROUND(SUM(ii.line_total_price), 2) AS total_price
FROM
    city AS ci,
    customer AS cu,
    invoice AS i,
    invoice_item AS ii,
    product AS pr
-- Устанавливаем связи между таблицами через соответствующие идентификаторы
WHERE
    ci.id = cu.city_id
    AND cu.id = i.customer_id
    AND i.id = ii.invoice_id
    AND ii.product_id = pr.id
-- Группируем результаты по названию города и названию продукта
GROUP BY
    ci.city_name,
    pr.product_name
-- Сортируем результаты по общей цене по убыванию, названию города и названию продукта
ORDER BY
    total_price DESC,
    ci.city_name,
    pr.product_name;
