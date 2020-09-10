/*
  To drop a column of a table, use the DROP COLUMN clause in the ALTER TABLE statement:

    ALTER TABLE table_name 
    DROP COLUMN column_name;

  When remove a column from a table, PostgreSQL will automatically remove all of the indexes and constraints
  that involved the dropped column.

  If the column that want to remove is used in other database objects such as views, triggers, stored procedures, etc.,
  it cannot drop the column because other objects are depending on it. In this case, need to add the CASCADE option
  to the DROP COLUMN clause to drop the column and all of its dependent objects:

    ALTER TABLE table_name 
    DROP COLUMN column_name CASCADE;


   To drop multiple columns of a table in a single command, you use multiple DROP COLUMN clause.
*/

CREATE TABLE developer (
  id SERIAL PRIMARY KEY NOT NULL,
  name VARCHAR (40) NOT NULL
);


CREATE TABLE structure_type (
  id SERIAL PRIMARY KEY NOT NULL,
  name VARCHAR (40)
);


CREATE TABLE structure (
  id SERIAL PRIMARY KEY NOT NULL,
  address VARCHAR(40),
  day_of_production DATE NOT NULL,
  developer_id INT NOT NULL,
  structure_id INT NOT NULL,
  FOREIGN KEY(developer_id) REFERENCES developer (id),
  FOREIGN KEY(structure_id) REFERENCES structure_type (id)
);

INSERT INTO
  developer
VALUES
  (default, 'Some Developer1'),
  (default, 'Some Developer2'),
  (default, 'Some Developer3'),
  (default, 'Some Developer4');

INSERT INTO
  structure_type
VALUES
  (default, 'House'),
  (default, 'Kastle'),
  (default, 'Hospital'),
  (default, 'School');

INSERT INTO
  structure
VALUES
  (default, 'Bla-bla street 9', '2020-01-01', 1, 1),
  (default, 'Bla-bla street 13', '2021-12-09', 1, 1),
  (default, 'Bla-bla street 16', '2020-11-11', 1, 1),
  (default, 'Bla-bla street 11', '2018-12-12', 1, 1),
  (default, 'Bla-bla street 19', '2018-02-08', 1, 1),
  (default, 'Bla-bla street 14', '2018-09-13', 1, 1),
  (default, 'Bla-bla street 26', '2019-12-02', 1, 1),
  (default, 'Bla-bla street 10', '2020-11-09', 1, 1),
  (default, 'Bla-bla street 15', '2022-04-03', 1, 1),
  (default, 'Bla-bla street 4', '2022-11-06', 1, 1),
  (default, 'Bla-bla street 17', '2019-01-01', 1, 1);

-- Drop tables.
ALTER TABLE structure
DROP COLUMN structure_id;

ALTER TABLE structure
DROP COLUMN developer_id;

DROP TABLE IF EXISTS structure;
DROP TABLE IF EXISTS structure_type;
DROP TABLE IF EXISTS developer;
