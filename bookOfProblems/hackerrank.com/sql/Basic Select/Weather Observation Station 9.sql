select distinct CITY from STATION where CITY regexp "^[^aeiou]";
---------
select distinct CITY from STATION where CITY rlike "^[^aeiou]";
---------
select distinct CITY from STATION where substring(CITY,1,1) not in ('a','e','i','o','u');
--------
select distinct CITY from STATION where mid(CITY,1,1) not in ('a','e','i','o','u');
--------
select distinct CITY from STATION where left(CITY,1) not in ('a','e','i','o','u');
--------
