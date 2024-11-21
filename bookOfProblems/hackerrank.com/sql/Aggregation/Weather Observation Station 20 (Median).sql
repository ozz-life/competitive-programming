WITH ranking AS (
    SELECT
        round(lat_n, 4) AS lat_n,
        rank() over(
            ORDER BY
                lat_n
        ) AS row_num
    FROM
        station
)
SELECT
    lat_n
FROM
    ranking
WHERE
    sno = (
        SELECT
            round(count(row_num) / 2)
        FROM
            ranking
    );

--------------------------------------------------------------------------------
WITH ranked AS (
    SELECT
        lat_n,
        row_number() over(
            ORDER BY
                lat_n
        ) AS id
    FROM
        station
)
SELECT
    round(lat_n, 4)
FROM
    ranked
WHERE
    id = (
        SELECT
            ceil(count(*) / 2)
        FROM
            station
    );

--------------------------------------------------------------------------------
SELECT
    ROUND(LAT_N, 4) AS median
FROM
    (
        SELECT
            LAT_N,
            ROW_NUMBER() OVER (
                ORDER BY
                    LAT_N
            ) AS rn_asc,
            ROW_NUMBER() OVER (
                ORDER BY
                    LAT_N DESC
            ) AS rn_desc
        FROM
            STATION
    ) AS subquery
WHERE
    rn_asc = rn_desc
    OR rn_asc + 1 = rn_desc
    OR rn_asc = rn_desc + 1;