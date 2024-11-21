SELECT
    name
FROM
    Customer
WHERE
    referee_id != 2
    OR referee_id IS NULL;

---
SELECT
    "name"
FROM
    customer
WHERE
    referee_id IS DISTINCT
FROM
    2;

---
SELECT
    c.name
FROM
    Customer AS c
WHERE
    (
        c.referee_id != 2
        OR c.referee_id IS NULL
    );

----
WITH not_2 AS(
    SELECT
        name,
        referee_id
    FROM
        Customer
    WHERE
        referee_id IS DISTINCT
    FROM
        2
)
SELECT
    name
FROM
    not_2;

----
SELECT
    name
FROM
    customer
WHERE
    referee_id IS NULL
    OR referee_id != 2;