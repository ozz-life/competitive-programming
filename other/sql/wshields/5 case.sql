-- Оператор CASE позволяет создать новое временное поле в базе данных, которое
-- станет меткой для данных на основе заданных пользователем условий.
-- ВНИМАНИЕ
-- Ключевое слово ELSE указывать не обязательно, но рекомендуется. В данных
-- могут быть значения, выходящие за рамки требуемых условий. Условие ELSE
-- фиксирует эти значения, и вы можете понять, что с ними делать. Если условие
-- ELSE не добавлено, любые результаты в вашем наборе данных, выходящие
-- за рамки требуемых условий, будут возвращены как значение NULL.
SELECT
    InvoiceDate,
    BillingAddress,
    BillingCity,
    Total,
    CASE
        WHEN TOTAL < 2.00 THEN 'Baseline Purchase'
        WHEN TOTAL BETWEEN 2.00
        AND 6.99 THEN 'Low Purchase'
        WHEN TOTAL BETWEEN 7.00
        AND 15.00 THEN 'Target Purchase'
        ELSE 'Top Performers'
    END AS PurchaseType
FROM
    invoices
ORDER BY
    BillingCity;

-- Ответим на следующие вопросы.
-- В каких городах осуществляются самые эффективные продажи?
-- Самые эффективные продажи в основном осуществляются в США или в других странах?
-- В каких городах совершается больше всего базовых покупок?
SELECT
    InvoiceDate,
    BillingAddress,
    BillingCity,
    Total,
    CASE
        WHEN TOTAL < 2.00 THEN 'Baseline Purchase'
        WHEN TOTAL BETWEEN 2.00
        AND 6.99 THEN 'Low Purchase'
        WHEN TOTAL BETWEEN 7.00
        AND 15.00 THEN 'Target Purchase'
        ELSE 'Top Performers'
    END AS PurchaseType
FROM
    invoices
WHERE
    PurchaseType = 'Top Performers'
ORDER BY
    BillingCity;

-- ПРИМЕЧАНИЕ
-- В примерах в этой главе мы использовали оператор CASE в части запро-
-- са SELECT после необходимых для отображения полей. Далее вы можете
-- встретить запрос, в котором оператор CASE содержится в условии WHERE
-- (редкий случай). Все, что сейчас важно, — это помнить, что оператор CASE
-- должен быть указан в условии SELECT, но ссылаться на него можно из дру-
-- гого места программного кода.
SELECT
    InvoiceDate,
    BillingAddress,
    BillingCity,
    Total,
    CASE
        WHEN BillingCountry = 'USA' THEN 'Domestic Sales'
        ELSE 'Foreign Sales'
    END AS SalesType
FROM
    invoices
ORDER BY
    SalesType;

-- Подсчет количества счетов на внутреннем рынке, превышающих $15
SELECT
    COUNT(*) AS CountOfDomesticSalesOver15
FROM
    invoices
WHERE
    BillingCountry = 'USA'
    AND Total > 15;