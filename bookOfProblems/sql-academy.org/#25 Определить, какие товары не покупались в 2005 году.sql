SELECT
    good_name
FROM
    Goods
    LEFT JOIN Payments ON Goods.good_id = Payments.good
    AND YEAR(Payments.date) = 2005
WHERE
    Payments.good IS NULL
GROUP BY
    good_id;