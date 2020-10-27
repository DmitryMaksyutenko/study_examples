/*
    JSON data types are for storing JSON (JavaScript Object Notation) data. Such data can also be stored as text,
    but the JSON data types have the advantage of enforcing that each stored value is valid according to the JSON rules.
    JSON is an open standard format that consists of key-values pairs. The main usage of JSON is to transform data
    between a server and web application. Its human-readable text.

    The json data type stores an exact copy of the input text, which processing functions must reparse on each execution;
    while jsonb data is stored in a decomposed binary format that makes it slightly slower to input due to added conversion
    overhead, but significantly faster to process, since no reparsing is needed. jsonb also supports indexing,
    which can be a significant advantage.

    Use UTF-8 when work with JSON or JSONB types.

    –> –>> Returns field of JSON-object by index or field name.
    #> #>> Returs field of JSON-object by path.
*/

-- Without processing.
SELECT '{"name": "value", "name": "value"}'::json;
SELECT '{"key": 1.1, "key": 1.1}'::json;

-- With processing.
SELECT '{"name": "value", "name": "value"}'::jsonb;
SELECT '{"key": 1.1, "key": 1.1}'::jsonb;


CREATE TABLE orders (
    id SERIAL PRIMARY KEY NOT NULL,
    info JSON NOT NULL
);


INSERT INTO
    orders
VALUES
    (default, '{"customer": "John Smith", "itmes": {"product": "beer", "qty": 6}}');

INSERT INTO
    orders
VALUES
    (default, '{ "customer": "Lily Bush", "items": {"product": "Diaper","qty": 24}}'),
    (default, '{ "customer": "Josh William", "items": {"product": "Toy Car","qty": 1}}'),
    (default, '{ "customer": "Mary Clark", "items": {"product": "Toy Train","qty": 2}}');


SELECT
    info
FROM
    orders;


SELECT
    info -> 'customer' AS customer
FROM
    orders;


SELECT
    info -> 'items' -> 'product' AS producr
FROM
    orders;


-- Updating.
UPDATE
    orders
SET
    info = replace(info::TEXT, '"itmes"', '"items"')::JSON
WHERE
    id = 1;


SELECT json_each (info)
FROM orders;


SELECT json_typeof (info->'items'->'qty')
FROM orders;


DROP TABLE IF EXISTS orders;
