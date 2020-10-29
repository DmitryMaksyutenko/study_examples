/*
    PostgreSQL allows columns of a table to be defined as variable-length multidimensional arrays.
    Arrays of any built-in or user-defined base type, enum type, composite type, range type,
    or domain can be created.


*/

CREATE TABLE contacts (
    id SERIAL PRIMARY KEY,
    name VARCHAR(100),
    phones TEXT []
);


INSERT INTO
    contacts (name, phones)
VALUES
(
    'John Doe',
    ARRAY [ '(408)-589-5846',
            '(408)-589-5555' ]
);


INSERT INTO contacts (name, phones)
VALUES
(
    'Lily Bush',
    '{"(408)-589-5841"}'
),
(
    'William Gate',
    '{"(408)-589-5842","(408)-589-58423"}'
);


-- Updating table.
UPDATE
    contacts
SET
    phones [2] = '(408)-589-5444'
WHERE id = 2;


UPDATE
    contacts
SET
    phones = array_append(phones, '(408)-589-5454')
WHERE id = 1;


UPDATE
    contacts
SET
    phones = array_cat(phones, ARRAY['(408)-589-5444','(408)-589-57777'])
WHERE id = 4;


-- Getting data form table.
SELECT
    phones -- [1],
    name
FROM
    contacts;


SELECT
    name
FROM
    contacts
WHERE
    phones [2] LIKE '(408)-589-55%';


SELECT
    name,
    phones[2:3]
FROM
    contacts
WHERE
    id = 4;


SELECT
    name,
    unnest(phones)
FROM
    contacts;


DROP TABLE IF EXISTS contacts;
