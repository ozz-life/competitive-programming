SELECT
    sum(city.population)
FROM
    city
    INNER JOIN country ON city.countrycode = country.code
WHERE
    continent = 'Asia';

--------------------------------------------------------------------------------
SELECT
    sum(a.population)
FROM
    CITY AS a
    INNER JOIN COUNTRY AS b ON a.countrycode = b.code
WHERE
    b.continent = 'Asia'