-- Pivot the OCCUPATIONS table and display names alphabetically under each occupation.
SELECT
    MAX(
        CASE
            WHEN Occupation = 'Doctor' THEN Name
        END
    ) AS Doctor,
    -- Display Doctor names
    MAX(
        CASE
            WHEN Occupation = 'Professor' THEN Name
        END
    ) AS Professor,
    -- Display Professor names
    MAX(
        CASE
            WHEN Occupation = 'Singer' THEN Name
        END
    ) AS Singer,
    -- Display Singer names
    MAX(
        CASE
            WHEN Occupation = 'Actor' THEN Name
        END
    ) AS Actor -- Display Actor names
FROM
    (
        -- Assign row numbers within each Occupation based on alphabetical sorting of names.
        SELECT
            Name,
            Occupation,
            ROW_NUMBER() OVER (
                PARTITION BY Occupation
                ORDER BY
                    Name
            ) AS rn
        FROM
            OCCUPATIONS
    ) AS pivot
GROUP BY
    rn;

-- Group rows based on the assigned row numbers to place names under respective occupations.
-- 1st The inner subquery assigns a unique row number (rn) to each Name within the same Occupation partition, sorting them alphabetically by Name.
-- then, The outer query uses CASE statements with MAX function to **pivot**the data, displaying names in the appropriate columns based on their Occupation and row number (rn).
-- The final result is achieved by grouping the rows based on the assigned row numbers (rn), thus placing the names underneath their corresponding occupations.
-- If there are no names for a specific occupation, the MAX function with CASE will return NULL, fulfilling the requirement.