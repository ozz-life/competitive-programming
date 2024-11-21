/*
 Manhattan Distance: |x1 - x2| + |y1 - y2|
 */
-- a = SELECT MIN(LAT_N) FROM Station
-- b = SELECT MIN(LONG_W) FROM Station
-- c = SELECT MAX(LAT_N) FROM Station
-- d = SELECT MAX(LONG_W) FROM Station
-- SELECT ROUND((c - a) + (d - b), 4) FROM Station;
SELECT
    ROUND(
        (MAX(LAT_N) - MIN(LAT_N)) + (MAX(LONG_W) - MIN(LONG_W)),
        4
    )
FROM
    Station;