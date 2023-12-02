select name from STUDENTS where Marks > 75 order by REGEXP_SUBSTR(name,".{3}$"),ID;
------
select name from STUDENTS where Marks > 75 order by right(name,3),ID;
------
select name from STUDENTS where Marks > 75 order by substring(name,-3),ID;
------
select name from STUDENTS where Marks > 75 order by mid(name,-3),ID;