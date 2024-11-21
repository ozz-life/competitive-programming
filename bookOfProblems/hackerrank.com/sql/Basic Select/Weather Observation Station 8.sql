SELECT
    DISTINCT CITY
FROM
    STATION
WHERE
    left(CITY, 1) IN ('a', 'e', 'i', 'o', 'u')
    AND right(CITY, 1) IN ('a', 'e', 'i', 'o', 'u');

---------
SELECT
    DISTINCT city
FROM
    station
WHERE
    city REGEXP '^[aeiou]'
    AND city REGEXP '[aeiou]$';