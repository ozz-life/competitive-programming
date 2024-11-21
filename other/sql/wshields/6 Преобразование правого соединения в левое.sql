SELECT
    *
FROM
    albums AS al
    RIGHT OUTER JOIN tracks AS t ON t.AlbumId = al.AlbumId;

-- аналогично
SELECT
    *
FROM
    tracks AS t
    LEFT OUTER JOIN albums AS al ON t.AlbumId = al.AlbumId