SELECT
    member_name,
    SUM(p.amount * p.unit_price) AS costs
FROM
    FamilyMembers AS fm
    LEFT JOIN Payments AS p ON fm.member_id = p.family_member
    LEFT JOIN Goods AS g ON p.good = g.good_id
    LEFT JOIN GoodTypes AS gt ON g.type = gt.good_type_id
WHERE
    p.date LIKE "2005-06%"
GROUP BY
    member_name;