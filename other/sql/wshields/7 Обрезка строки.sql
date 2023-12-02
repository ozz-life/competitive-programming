SELECT
    PostalCode,
    LENGTH(PostalCode) AS [Postal Code Length]
FROM
    customers
WHERE
    Country = "USA";

-- SUBSTR(X,Y)Извлекает все символы до позиции X, начиная с позиции Y.
-- SUBSTR(X,Y,Z)Извлекает из строки X подстроку заданной длины Z начиная от заданной начальной позиции Y.
SELECT
    PostalCode,
    SUBSTR(PostalCode, 4, 2) AS [Five Digit Postal Code],
    SUBSTR(PostalCode, -4) AS [ZIP + 4 Code]
FROM
    customers
WHERE
    Country = "USA";

-- ПРИМЕЧАНИЕ
-- Функции UPPER() и LOWER() работают только с символами ASCII. Любые сим-
-- волы, изначально отформатированные в Юникоде, остаются без изменений.
SELECT
    FirstName AS [First Name Unmodified],
    UPPER(FirstName) AS [First Name in UPPERCASE],
    LOWER(FirstName) AS [First Name in lowercase],
    UPPER(FirstName) || ' ' || UPPER(LastName) AS [Full Name in
UPPERCASE]
FROM
    customers