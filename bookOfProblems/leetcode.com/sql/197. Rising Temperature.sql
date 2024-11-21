-- https://leetcode.com/problems/rising-temperature/editorial/?envType=study-plan-v2&envId=top-sql-50

SELECT
    a.id
FROM
    weather a
    JOIN weather b ON a.recorddate - 1 = b.recorddate
WHERE
    b.temperature < a.temperature;