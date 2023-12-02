SELECT
    DISTINCT fm.status
FROM
    FamilyMembers AS fm
    JOIN Payments AS p ON fm.member_id = p.family_member
    JOIN Goods AS g ON p.good = g.good_id
WHERE
    good_name LIKE 'potato';