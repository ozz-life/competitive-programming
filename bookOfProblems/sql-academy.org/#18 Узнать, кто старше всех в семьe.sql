SELECT
    member_name
FROM
    familymembers
ORDER BY
    date(birthday) ASC
LIMIT
    1;