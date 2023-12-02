SELECT
    concat(name, initials)
FROM
    (
        SELECT
            *,
            CASE
                WHEN occupation = 'Professor' THEN '(P)'
                WHEN occupation = 'Doctor' THEN '(D)'
                WHEN occupation = 'Actor' THEN '(A)'
                WHEN occupation = 'Singer' THEN '(S)'
            END AS initials
        FROM
            Occupations
    ) AS cte
ORDER BY
    name;

SELECT
    concat (
        'There are a total of ',
        cnt,
        ' ',
        lower(occupation),
        's.'
    )
FROM
    (
        SELECT
            count(Name) cnt,
            occupation
        FROM
            Occupations
        GROUP BY
            occupation
    ) AS cte2
ORDER BY
    cnt,
    occupation;

--------------------------------------------------------------------------------
SELECT
    concat (name, "(", left(occupation, 1), ")")
FROM
    occupations
ORDER BY
    name;

SELECT
    concat(
        "There are a total of ",
        count(occupation),
        " ",
        lower(occupation),
        "s."
    )
FROM
    occupations
GROUP BY
    occupation
ORDER BY
    count(occupation),
    occupation;