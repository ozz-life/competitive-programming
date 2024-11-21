SELECT
    member_name,
    STATUS,
    sum(p.amount * p.unit_price) AS costs
FROM
    Payments AS p
    INNER JOIN FamilyMembers AS fm ON p.family_member = fm.member_id
WHERE
    date LIKE '2005%'
GROUP BY
    family_member;