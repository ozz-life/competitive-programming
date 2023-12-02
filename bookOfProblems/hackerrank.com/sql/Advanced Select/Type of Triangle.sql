SELECT
    CASE
        WHEN ((A + B) <= C)
        OR ((A + C) <= B)
        OR ((B + C) <= A) THEN 'Not A Triangle'
        WHEN (A = B)
        AND (B = C) THEN 'Equilateral'
        WHEN (A = C)
        OR (B = C)
        OR (B = A) THEN 'Isosceles'
        WHEN (A != B)
        AND (B != C) THEN 'Scalene'
    END AS Result
FROM
    TRIANGLES;

---------------
SELECT
    CASE
        WHEN (A + B <= C)
        OR (A + C <= B)
        OR (B + C <= A) THEN 'Not A Triangle'
        WHEN A = B
        AND B = C THEN 'Equilateral'
        WHEN A = B
        OR B = C
        OR A = C THEN 'Isosceles'
        ELSE 'Scalene'
    END AS Result
FROM
    TRIANGLES;