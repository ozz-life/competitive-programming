-- По умолчанию данные будут отсор­тированы в порядке возрастания от A до Z.
-- Специальное ключевое слово ASC, определяющее порядок сортировки, необязательно.
-- Для сортировки в порядке убывания от Z до A необходимо после сортируемого поля добавить ключевое слово DESC.

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
;

-- ПРИМЕЧАНИЕ
-- Если условие ORDER BY отсутствует, каждый запрос будет возвращать дан-
-- ные в том порядке, в котором они были изначально сохранены в таблице.

-- ПРИМЕЧАНИЕ
-- Если вы используете условие ORDER BY для столбца, в котором имеются
-- пустые строки, вы увидите, что эти значения будут отображаться в начале
-- списка как NULL (если сортировка осуществляется в порядке возрастания).