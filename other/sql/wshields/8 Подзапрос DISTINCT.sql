-- получим список только тех треков, которые появляются в счетах,
-- без дубликатов.
SELECT
    DISTINCT TrackId
FROM
    invoice_items
ORDER BY
    TrackId;

-- Теперь нам необходимо написать запрос, перечисляющий
-- все треки из таблицы tracks, которые не входят (NOT IN) в созданный первым
-- запросом список.
SELECT
    TrackId,
    Composer,
    Name
FROM
    tracks
WHERE
    TrackId NOT IN (
        SELECT
            DISTINCT TrackId
        FROM
            invoice_items
    )