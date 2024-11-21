SELECT
    city,
    length(city)
FROM
    station
WHERE
    city = (
        SELECT
            city
        FROM
            station
        ORDER BY
            length(city),
            city
        LIMIT
            1
    )
    OR city = (
        SELECT
            city
        FROM
            station
        ORDER BY
            length(city) DESC,
            city
        LIMIT
            1
    );

--------------------
SELECT
    CITY,
    MIN(LENGTH(CITY))
FROM
    STATION
GROUP BY
    CITY
ORDER BY
    MIN(LENGTH(CITY)) ASC,
    CITY ASC
LIMIT
    1;

SELECT
    CITY,
    MAX(LENGTH(CITY))
FROM
    STATION
GROUP BY
    CITY
ORDER BY
    MAX(LENGTH(CITY)) DESC,
    CITY
LIMIT
    1;