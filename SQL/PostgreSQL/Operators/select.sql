/*
    One of the most complex statement in PostgreSQL.

    SELECT - retreinves data from a single table.

    [WITH with_queries] SELECT slect_list FROM table_expression [sort_expression]

    SELECT
        column1,         select_list
        column2,
            .
            .
            .
    FROM
        table_name;     table_expression
*/


-- SELECT as calculator.
SELECT 3 * 4;
SELECT 5 + 5 * 10;
SELECT (5 + 5) * 10;
SELECT 1 / 0;               -- ERROR:  division by zero.

-- SELECT can list the return value from function.
SELECT random();
SELECT ceil(random() * 10);
SELECT format('format text: %s, %20s, %1$s', 6, 'text');

-- SELECT data from table.
SELECT * FROM actor; -- A bad practice.
SELECT actor_id, first_name, last_name, last_update FROM actor; -- equivalent to 31 row.
SELECT count(*) FROM actor;
SELECT first_name FROM actor;
SELECT first_name, last_name, actor_id FROM actor;

-- SELECT with column alias AS and concationation operator ||.
SELECT
    first_name || ' ' || last_name AS full_name,
    last_update
FROM
    actor;

SELECT 5 * 5 AS result;