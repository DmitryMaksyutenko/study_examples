/*
    Types described in Datatypes/datatypes.sql
*/

CREATE TABLE types_test (
    id SERIAL PRIMARY KEY NOT NULL,
    char_type CHAR(1),
    varchar_type VARCHAR(10),
    text_type TEXT
);

-- Error. Value to long for type char.
INSERT INTO
    types_test
VALUES
    (default, 'test', 'some text', 'the red fox jumped over the lazy dog');

-- Error. Value to long for type varchar.
INSERT INTO
    types_test
VALUES
    (default, 't', 'some text longer then ten characters.', 'the red fox jumped over the lazy dog');

-- Success.
INSERT INTO
    types_test
VALUES
    (default, 't', 'some text', 'the red fox jumped over the lazy dog');


DROP TABLE IF EXISTS types_test;
