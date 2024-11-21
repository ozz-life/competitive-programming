select distinct city from station
where city like 'a%' or city like 'e%' or city like 'i%' or city like 'o%' or city like 'u%';
---------------
SELECT DISTINCT CITY FROM STATION WHERE CITY REGEXP '^[AEIOU]';
--------------
SELECT DISTINCT CITY FROM STATION WHERE SUBSTR(UPPER(CITY),1,1) IN ('A','E','I','O','U');
--------------
select distinct CITY from STATION where left(CITY,1) in ('a','e','i','o','u');