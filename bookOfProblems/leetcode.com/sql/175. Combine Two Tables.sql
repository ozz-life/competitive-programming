SELECT
    firstName,
    lastName,
    city,
    state
FROM
    Person
    LEFT JOIN Address ON Person.personId = Address.personId;

-- 2nd way (table1 LEFT JOIN table2 USING column_name)
SELECT
    P.firstName,
    P.lastName,
    A.city,
    A.state
FROM
    Person P
    LEFT JOIN Address A USING (personId)