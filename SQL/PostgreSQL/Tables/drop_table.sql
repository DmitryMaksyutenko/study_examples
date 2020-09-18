/*
   To drop a table from the database, use the DROP TABLE statement:

    DROP TABLE [IF EXISTS] table_name
    [CASCADE | RESTRICT];

  To remove multiple tables at once, place a comma-separated list of tables after the DROP TABLE keywords:

    DROP TABLE [IF EXISTS]
       table_name_1,
       table_name_2,
       ...
*/

-- Error message.
DROP TABLE some_table;

-- NO error message.
DROP TABLE IF EXISTS some_table;

-- Drop table with dependences.
CREATE TABLE person_status (
  status_id SERIAL PRIMARY KEY NOT NULL,
  status VARCHAR(30) NOT NULL
);

CREATE TABLE person (
  id SERIAL PRIMARY KEY NOT NULL,
  name VARCHAR(30) NOT NULL,
  status INT NOT NULL,
  FOREIGN KEY (status) REFERENCES person_status (status_id)
);

-- Error.
DROP TABLE person_status;

-- No error.
DROP TABLE person_status CASCADE;

DROP TABLE person;
