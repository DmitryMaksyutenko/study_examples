/*
     A valid values for TRUE and FALSE in PostgreSQL.

        TRUE      |     FALSE
        ---------------------
        true      |     false
        'true'    |     'false'
         't'      |       'f'
         'y'      |       'n'
        'yes'     |       'no'
         '1'       |      '0'
*/


CREATE TABLE stock_availiability (
    serial_num CHAR(10) PRIMARY KEY NOT NULL,
    available BOOLEAN NOT NULL
);

INSERT INTO
    stock_availiability
VALUES
    ('123AAcr47I', true),
    ('125Arcrt8I', false),
    ('0e3aAjj070', 'true'),
    ('1e8CACC07C', 'false'),
    ('9e3aAty979', 't'),
    ('120ddaA74T', 'f'),
    ('222ctcyy8u', 'y'),
    ('093Atcw4qq', 'n'),
    ('g23iicry8c', 'yes'),
    ('1i3Aocrccc', 'no'),
    ('ppAAA12476', '1'),
    ('52378cr477', '0');

SELECT
    serial_num AS num,
    available AS is_available
FROM
    stock_availiability
WHERE
    available;

SELECT
    serial_num AS num,
    available AS is_available
FROM
    stock_availiability
WHERE
    NOT available;


DROP TABLE IF EXISTS stock_availiability;
