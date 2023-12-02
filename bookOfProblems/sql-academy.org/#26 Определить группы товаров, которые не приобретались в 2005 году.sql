SELECT
    good_type_name
FROM
    GoodTypes
WHERE
    good_type_id NOT IN (
        SELECT
            good_type_id
        FROM
            Goods
            JOIN Payments ON Goods.good_id = Payments.good
            AND YEAR(date) = 2005
            JOIN GoodTypes ON GoodTypes.good_type_id = Goods.type
    );