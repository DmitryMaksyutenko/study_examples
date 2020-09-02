/*
  To change the structure of an existing table, use PostgreSQL ALTER TABLE statement.

  ALTER TABLE table_name action;

    PostgreSQL provides you with many actions:

      Add a column.
      Drop a column.
      Change the data type of a column.
      Rename a column.
      Set a default value for the column.
      Add a constraint to a column.
      Rename a table.
*/

CREATE TABLE IF NOT EXISTS test_user
(
  id SERIAL PRIMARY KEY NOT NULL,
  first_name VARCHAR(20) NOT NULL,
  last_name VARCHAR(30) NOT NULL
);

-- Add column.
ALTER TABLE
  test_user
ADD COLUMN
  day_of_birth DATE NOT NULL;

-- Remove column.
ALTER TABLE
  test_user
DROP COLUMN
  day_of_birth;

-- Rename column.
ALTER TABLE
  test_user
RENAME COLUMN id TO user_id;

-- Set default value.
ALTER TABLE
  test_user
ALTER COLUMN
  first_name
SET DEFAULT
  'FirstName',
ALTER COLUMN
  last_name
SET DEFAULT
  'LastName';

-- Add check.
ALTER TABLE
  test_user
ADD CHECK
  (first_name IN ('Dima', 'dima'));

-- Add constraint.
ALTER TABLE
  test_user
ADD CONSTRAINT
  unique_last_name
  UNIQUE (last_name);

-- Table rename.
ALTER TABLE
  test_user
RENAME TO
  new_user;

DROP TABLE IF EXISTS new_user;
