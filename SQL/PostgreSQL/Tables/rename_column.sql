/*
   To rename a column of a table, you use the ALTER TABLE statement with RENAME COLUMN clause.

    ALTER TABLE table_name
    RENAME COLUMN column_name TO new_column_n;

  To rename multiple columns, execute the ALTER TABLE RENAME COLUMN statement multiple times, one column at a time:

    ALTER TABLE table_name
    RENAME column_name1 TO new_column_name1;

    ALTER TABLE table_name
    RENAME column_name2 TO new_column_name2;
*/


CREATE TABLE person (
  id SERIAL PRIMARY KEY NOT NULL,
  name VARCHAR(30) NOT NULL,
  surname VARCHAR(30) NOT NULL,
  type_id INT NOT NULL,
  FOREIGN KEY (type_id) REFERENCES person_type (type_id)
);

CREATE TABLE person_type (
  type_id SERIAL PRIMARY KEY NOT NULL,
  type VARCHAR(50) NOT NULL
);

INSERT INTO
  person_type
VALUES
  (default, 'Admin'),
  (default, 'User'),
  (default, 'Customer');

INSERT INTO
  person
VALUES
  (default, 'Nanme', 'surname', 1),
  (default, 'Nanme', 'surname', 1),
  (default, 'Nanme', 'surname', 3),
  (default, 'Nanme', 'surname', 2),
  (default, 'Nanme', 'surname', 2),
  (default, 'Nanme', 'surname', 3);

CREATE VIEW get_persons_types
AS SELECT
  p.name,
  p.surname,
  t.type
FROM
  person p
INNER JOIN person_type t ON t.type_id = p.type_id;


-- Column renaming.
ALTER TABLE
  person
RENAME COLUMN name TO first_name;

ALTER TABLE
  person
RENAME COLUMN surname TO last_name;

DROP TABLE IF EXISTS person CASCADE;
DROP TABLE IF EXISTS person_type;
