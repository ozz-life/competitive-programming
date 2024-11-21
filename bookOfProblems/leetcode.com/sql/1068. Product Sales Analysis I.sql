SELECT
    p.product_name,
    s.year,
    s.price
FROM
    Sales AS s
    INNER JOIN Product AS p ON s.product_id = p.product_id;

--------
SELECT
    p.product_name,
    s.year,
    s.price
FROM
    Sales s
    NATURAL JOIN Product p;

--------
SELECT
    product_name,
    year,
    price
FROM
    Sales
    INNER JOIN Product USING (product_id);