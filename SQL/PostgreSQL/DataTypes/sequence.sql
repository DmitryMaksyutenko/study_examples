/*
  A sequence in PostgreSQL is a user-defined schema-bound object that generates a sequence of integers based on
  a specified specification.

  CREATE SEQUENCE [ IF NOT EXISTS ] sequence_name
    [ AS { SMALLINT | INT | BIGINT } ]
    [ INCREMENT [ BY ] increment ]
    [ MINVALUE minvalue | NO MINVALUE ]
    [ MAXVALUE maxvalue | NO MAXVALUE ]
    [ START [ WITH ] start ] 
    [ CACHE cache ] 
    [ [ NO ] CYCLE ]
    [ OWNED BY { table_name.column_name | NONE } ]

  To get the next value from the sequence use the nextval() function.
*/

CREATE SEQUENCE test_seq
INCREMENT 5
START 100;

SELECT nextval('test_seq');


CREATE SEQUENCE three
INCREMENT -1
MINVALUE 1
MAXVALUE 3
START 3
CYCLE;

SELECT nextval('three');


CREATE TABLE test_table (
  id SERIAL NOT NULL,
  name VARCHAR(50) NOT NULL
);

CREATE SEQUENCE for_test
INCREMENT 12
MINVALUE 3
MAXVALUE 133
START 55
CYCLE
OWNED BY test_table.id;

INSERT INTO
  test_table
VALUES
  (nextval('for_test'), 'Dima'),
  (nextval('for_test'), 'Ann'),
  (nextval('for_test'), 'Sam');

SELECT * FROM test_table;


DROP SEQUENCE IF EXISTS test_seq;
DROP SEQUENCE IF EXISTS three;
DROP TABLE IF EXISTS test_table;
