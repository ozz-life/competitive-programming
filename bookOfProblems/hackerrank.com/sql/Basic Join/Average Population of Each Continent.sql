SELECT
    COUNTRY.Continent,
    floor(avg(CITY.population))
FROM
    CITY
    INNER JOIN COUNTRY ON City.CountryCode = Country.Code
GROUP BY
    COUNTRY.Continent;