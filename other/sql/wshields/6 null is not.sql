-- IS NULL в условии WHERE вернет только нулевые значения.
-- NOT NULL вернет только значения, которые не были нулевыми.
SELECT
    ar.ArtistId AS [ArtistId From Artists Table],
    al.ArtistId AS [ArtistId From Albums Table],
    ar.Name AS [Artist Name],
    al.Title AS [Album Title]
FROM
    artists AS ar
    LEFT OUTER JOIN albums AS al ON ar.ArtistId = al.ArtistId
WHERE
    al.ArtistId IS NULL;
    
-- ВНИМАНИЕ
-- При работе со значениями NULL необходимо использовать операторы IS
-- и NOT, а не оператор равенства =. Нулевые значения указывают на недо-
-- статок данных. Оператор = сравнивает значения двух элементов. Нулевые
-- значения не содержат значений, поэтому их нельзя сравнивать, используя
-- оператор =. Использование оператора = приведет к ошибке.