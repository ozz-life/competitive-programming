/*
 -- a = SELECT MIN(LAT_N) FROM Station
 -- b = SELECT MAX(LAT_N) FROM Station
 -- c = SELECT MIN(LONG_W) FROM Station
 -- d = SELECT MAX(LONG_W) FROM Station
 
 Euclidean Distance = Square Root((q1-p1)^2 + (q2-p2)^2)
 */
SELECT
    ROUND(
        SQRT(
            POWER(MAX(LAT_N) - MIN(LAT_N), 2) + POWER(MAX(LONG_W) - MIN(LONG_W), 2)
        ),
        4
    )
FROM
    Station;