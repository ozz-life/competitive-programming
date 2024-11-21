SELECT
    FirstName 'ПЕРЫ Name',
    lastname [Руссо Фамило],
    Company,
    Phone CELL,
    Email EMAIL
FROM
    customers
ORDER BY
    LastName DESC
LIMIT
    12
    
-- ПРИМЕЧАНИЕ
-- Нет необходимости всегда использовать условие LIMIT вместе с ORDER BY.
-- В большинстве случаев имеет смысл упорядочить результаты по определен-
-- ным критериям, прежде чем ограничивать их. Если условие ORDER BY не
-- используется, результаты оператора LIMIT будут возвращены в том порядке,
-- в котором они были изначально добавлены в таблицу.