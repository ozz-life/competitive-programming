-- Не забываем поставить where, а то удалит все записи
DELETE FROM
    clown_info
WHERE
    activities = 'танцы';

--Чтобы заменить участок. Вставляем новый. Удаляем старый.
-- Если несколько раз повысить цены, повышаем с больших и двигаемся в сторону меньших,
-- чтобы меньшие не подорожали два раза.

-- Чтобы не удалить посторонние
-- записи, сначала выполните
-- команду SELECT.