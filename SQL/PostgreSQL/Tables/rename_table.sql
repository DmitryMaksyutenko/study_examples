/*
  To rename an existing table, use the ALTER TABLE statement as follows:

    ALTER TABLE table_name
    RENAME TO new_table_name;
    In this statement:

    First, specify the name of the table which you want to rename after the ALTER TABLE clause.
    Second, give the new table name after the RENAME TO claus

    ALTER TABLE IF EXISTS table_name
    RENAME TO new_table_name;

    To avoid error messages in the case table doesn't exist.

  To rename multiple tables, execute multiple ALTER TABLE RENAME TO statements.
  It’s not possible to rename multiple taable using a singe ALTER TABLE statement.

  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  When rename a table to the new one, PostgreSQL will automatically update its dependent objects
  such as foreign key constraints, views, and indexes.
*/

CREATE TABLE position (
  id SERIAL PRIMARY KEY NOT NULL,
  position_name VARCHAR(30)
);

CREATE TABLE person (
  id SERIAL PRIMARY KEY NOT NULL,
  position_id INT REFERENCES position(id) NOT NULL,
  first_name VARCHAR(30) NOT NULL,
  last_name VARCHAR(40) NOT NULL
);

INSERT INTO
  position
VALUES
  (default, 'doctor'),
  (default, 'nurse'),
  (default, 'manager');

INSERT INTO
  person
VALUES
  (default, 1, 'Dima', 'Maksyutenko'),
  (default, 1, 'Sam', 'Vinchester'),
  (default, 2, 'Anna', 'Pola'),
  (default, 2, 'Dina', 'Gatc'),
  (default, 3, 'John', 'Smith'),
  (default, 3, 'Dan', 'Raim'),
  (default, 2, 'Elen', 'Goog'),
  (default, 3, 'Gregor', 'Natc'),
  (default, 3, 'Nana', 'Lo');

-- Managers view.
CREATE VIEW select_all_managers AS
SELECT
  per.first_name AS "name",
  per.last_name AS "last name",
  pos.position_name AS "position"
FROM
  person per
INNER JOIN
  position pos
ON
  per.position_id = 3 AND pos.id = 3
ORDER BY
  per.first_name;

-- Doctors view.
CREATE VIEW select_all_doctors AS
SELECT
  per.first_name AS "name",
  per.last_name AS "last name",
  pos.position_name AS "position"
FROM
  person per
INNER JOIN
  position pos
ON
  per.position_id = 1 AND pos.id = 1
ORDER BY
  per.first_name;

-- Nurse view.
CREATE VIEW select_all_nurse AS
SELECT
  per.first_name AS "name",
  per.last_name AS "last name",
  pos.position_name AS "position"
FROM
  person per
INNER JOIN
  position pos
ON
  per.position_id = 2 AND pos.id = 2
ORDER BY
  per.first_name;


-- Renaming.
ALTER TABLE person
RENAME TO employee;


DROP TABLE IF EXISTS employee CASCADE;
DROP TABLE IF EXISTS position;
