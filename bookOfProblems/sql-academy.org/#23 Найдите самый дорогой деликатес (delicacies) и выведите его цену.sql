SELECT
    good_name,
    unit_price
FROM
    FamilyMembers AS fm
    LEFT JOIN Payments AS p ON fm.member_id = p.family_member
    LEFT JOIN Goods AS g ON p.good = g.good_id
    LEFT JOIN GoodTypes AS gt ON g.type = gt.good_type_id
WHERE
    gt.good_type_name = 'delicacies'
    AND unit_price = (
        SELECT
            MAX(unit_price)
        FROM
            Goods
    )
GROUP BY
    good_name,
    unit_price
LIMIT
    1;