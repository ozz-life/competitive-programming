SELECT
    round(LONG_W, 4)
FROM
    station
WHERE
    LAT_N =(
        SELECT
            min(LAT_N)
        FROM
            station
        WHERE
            LAT_N > 38.7780
    );