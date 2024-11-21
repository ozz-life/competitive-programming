select distinct city from station
where city like '%a' or city like '%e' or city like '%i' or city like '%o' or city like '%u';
--------
select distinct CITY from STATION where CITY regexp "[aeiou]$";
--------
select distinct CITY from STATION where CITY rlike "[aeiou]$";
--------
select distinct CITY from STATION where substring(CITY,length(CITY)) in ('a','e','i','o','u');
--------
select distinct CITY from STATION where mid(CITY,length(CITY)) in ('a','e','i','o','u');
--------
select distinct CITY from STATION where right(CITY,1) in ('a','e','i','o','u');
