/*
    The COALESCE function returns the first of its arguments that is not NULL.
    NULL is returnd only if all arguments are NULL,

        COALESCE (value [, ...])

    It is often used to substitute a default value for NULL values when data is
    retreived for display.

    Like a CASE expression, COALESCE only evaluates the arguments that are needed
    to determine the result.
*/

SELECT COALESCE(NULL, NULL, 1, 2); -- Returns 1

CREATE TABLE orders (
    order_id SERIAL PRIMARY KEY NOT NULL,
    staff TEXT NOT NULL,
    manufacturer VARCHAR(100) DEFAULT NULL
);

INSERT INTO
    orders
VALUES
    (default, 'some staf 1', 'manufacturer one'),
    (default, 'some staf 2', 'manufacturer one'),
    (default, 'some staf 3', 'manufacturer one'),
    (default, 'some staf 4', 'manufacturer one'),
    (default, 'some staf 5', default);

SELECT
    staff,
    manufacturer
FROM
    orders;

SELECT
    staff,
    COALESCE(manufacturer, 'Not specified')
FROM
    orders;

DROP TABLE IF EXISTS orders;