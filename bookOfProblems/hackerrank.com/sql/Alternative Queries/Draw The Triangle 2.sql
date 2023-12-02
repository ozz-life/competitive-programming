WITH recursive stars AS (
    SELECT
        1 AS n,
        cast('*' AS char(39)) AS str
    UNION
    ALL
    SELECT
        n + 1,
        concat (str, ' ', "*")
    FROM
        stars
    WHERE
        n < 20
)
SELECT
    str
FROM
    stars;

--------------------------------------------------------------------------------

WITH recursive cte(num) AS (
    SELECT
        1
    UNION
    ALL
    SELECT
        num + 1
    FROM
        cte
    WHERE
        num < 20
)
SELECT
    repeat('* ', num)
FROM
    cte;