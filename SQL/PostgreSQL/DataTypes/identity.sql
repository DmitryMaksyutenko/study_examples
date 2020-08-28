/*
  Constraint GENERATED AS IDENTITY that allows to automatically assign a unique number to a column.

  The GENERATED AS IDENTITY constraint is the SQL standard-conforming variant of the good old SERIAL column.

    column_name type GENERATED { ALWAYS | BY DEFAULT } AS IDENTITY[ ( sequence_option ) ]

*/

CREATE TABLE color (
    color_id INT GENERATED ALWAYS AS IDENTITY,
    color_name VARCHAR NOT NULL
);

INSERT INTO
  color
VALUES
  (default, 'Red');

-- ERROR
INSERT INTO color (color_id, color_name)
VALUES (2, 'Green');

INSERT INTO color (color_id, color_name)
OVERRIDING SYSTEM VALUE 
VALUES(2, 'Green');

DROP TABLE color;
