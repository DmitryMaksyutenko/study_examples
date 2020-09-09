/*
  To add a new column to an existing table, use the ALTER TABLE ADD COLUMN statement:

  ALTER TABLE table_name
  ADD COLUMN new_column_name data_type constraint;

  First, specify the name of the table to add a new column to, after the ALTER TABLE keyword.
  Second, specify the name of the new column as well as its data type and constraint after the ADD COLUMN keywords.

  When add a new column to the table, PostgreSQL appends it at the end of the table.
  PostgreSQL has no option to specify the position of the new column in the table.

  To add multiple columns to an existing table, use multiple ADD COLUMN clauses in the ALTER TABLE.
*/

CREATE TABLE person (
  id INT PRIMARY KEY NOT NULL,
  first_name VARCHAR(30) NOT NULL
);

CREATE SEQUENCE person_id_seq AS integer;
ALTER SEQUENCE person_id_seq OWNED BY person.id;

ALTER TABLE person
ALTER COLUMN id
  SET DEFAULT nextval('person_id_seq');

ALTER TABLE person
ADD COLUMN
  last_name VARCHAR(40) NOT NULL;

ALTER TABLE person
ADD COLUMN
  email VARCHAR(40),
ADD COLUMN
  phone VARCHAR(12);

-- Add constrains.
UPDATE person
SET
  phone = 'no'
WHERE
  id = 1
  OR
  id = 2
  OR
  id = 3;

ALTER TABLE person
ALTER COLUMN phone
  SET NOT NULL;

DROP TABLE IF EXISTS person;
