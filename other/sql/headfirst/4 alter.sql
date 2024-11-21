-- Изменение типа данных приведёт к потере данных, а если типы совместимы, то усечение данных.

-- CHANGE 
-- MODIFY
-- ADD
-- DROP

ALTER TABLE
    my_contacts
ADD
    COLUMN contact_id INT NOT NULL AUTO_INCREMENT FIRST,
ADD
    PRIMARY KEY (contact_id);

ALTER TABLE
    my_contacts
ADD
    COLUMN phone varchar(10);

ALTER TABLE
    my_contacts
ADD
    COLUMN phone varchar(10)
AFTER
    first_name;
    
-- Переименовать таблицу
alter table my_contacts
RENAME to myyy_contacts;

-- Удалить столбец из таблицу
alter table myyy_contacts
drop column email