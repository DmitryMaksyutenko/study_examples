/*
    The hstore is the data type for storing sets of key/value pairs
    within a single PostgreSQL value. This can be useful in various scenarios,
    such as rows with many attributes that are rarely examined, or semi-structured data.

    Keys and values are simply text strings.
        key => value

    For enabling the hstore:
        CREATE EXTENSION hstore;

    Each key in an hstore is unique. If key has a duplicate, only one will be stored
    in hstore.

    A value can be SQL NULL. The key can't be NULL.
*/

CREATE TABLE books (
    id SERIAL PRIMARY KEY,
    title VARCHAR(255),
    attr hstore
);

DROP TABLE IF EXISTS books;


-- Insert data into hstore.
INSERT INTO
    books
VALUES (
    default,
    'The Hobbit',
    '
    "paperback" => "234",
    "publisher" => "Kiev",
    "language" => "English",
    "ISBN-13" => "978-78567578576",
    "weight" => "11.2"
    '
);

INSERT INTO
    books (title, attr)
VALUES (
    'PostgreSQL',
    '
    "paperback" => "33",
    "publisher" => "postgrestutoria.com",
    "language" => "English",
    "ISBN-13" => "999-34534545",
    "weight" => "7.0"
    '
);


-- Get data from hstore.
SELECT
    attr
FROM
    books;

SELECT
    title, attr -> 'publisher'
FROM
    books
WHERE
    attr -> 'publisher' LIKE 'K%';


-- Add key/value pairs to existin row.
UPDATE books
SET
    attr = attr || '"freeshipping" => "yes"'::hstore;

---------------------------------------------------------
SELECT
    title,
    attr -> 'freeshipping' AS freeshipping
FROM
    books;


-- Update existing key/value pair.
UPDATE books
SET
    attr = attr || '"freeshipping"=>"no"' :: hstore
WHERE
    title = 'The Hobbit';


-- Remove existing pair.
UPDATE books
SET attr = delete(attr, 'freeshipping');


-- Check for a specific key in hstore column.
SELECT
  title,
  attr->'publisher' as publisher,
  attr
FROM
    books
    WHERE
        attr ? 'publisher';


-- Check for a key-value pair.
SELECT
    title
FROM
    books
WHERE
    attr @> '"weight"=>"11.2"':: hstore;


SELECT
    title
FROM
    books
WHERE
    attr ?& ARRAY [ 'language', 'weight'  ];
