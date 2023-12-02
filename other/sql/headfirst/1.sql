CREATE DATABASE gregs_list;

USE gregs_list;

CREATE TABLE doughnut_list (
    doughnut_name varchar(10),
    doughnut_type varchar(6),
    doughnut_cost DEC(3, 2) NOT NULL DEFAULT 1.00
);

--- Пример под MySQL
CREATE TABLE my_contacts (
    contact_id INT NOT NULL AUTOINCREMENT,
    last_name varchar(30) NOT NULL,
    first_name varchar(20) NOT NULL,
    email varchar(50),
    gender char(1),
    birthday date,
    profession varchar(50),
    location varchar(50),
    STATUS varchar(20),
    interests varchar(100),
    seeking varchar(100),
    PRIMARY KEY (contact_id)
);

--- Пример под SQLite
CREATE TABLE people (
   person_id INTEGER PRIMARY KEY AUTOINCREMENT,
   first_name text NOT NULL,
   last_name text NOT NULL
);

DESC my_contacts;

-- вывести таблицу, в SQLite ошибка
DROP TABLE my_contacts;

-- Удаляет таблицу СО ВСЕМИ данными.
INSERT INTO
    my_contacts (first_name, last_name)
VALUES
    ('stas', 'oz');

-- Изменение порядка столбцов
-- Порядок столбцов можно изменить — при условии, что зна­чения будут перечисляться
--  в соответствующем порядке!
-- Не указаны имена столбцов
-- Список столбцов можно опустить, но тогда все значения должны
-- быть указаны в порядке перечисления столбцов при создании
-- таблицы