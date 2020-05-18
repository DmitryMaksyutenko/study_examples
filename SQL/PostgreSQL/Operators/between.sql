/*
  The BETWEEN operator used to match a value against a range of values.

    value BETWEEN low AND high;                  <--|
    value >= low and value <= high; equivalent to --|

    value NOT BETWEEN low AND high;            <--|
    value < low OR value > higha; equivalent to --|

    Often used the WHERE clause of a SELECT, INSERT, UPDATE or DELETE statement.
*/

SELECT
    first_name,
    last_name,
    actor_id
FROM
    actor
WHERE
    actor_id BETWEEN 8 AND 100;

SELECT
    payment_id,
    customer_id,
    payment_date,
    amount
FROM
    payment
WHERE
    payment_date BETWEEN '2007-02-07' AND '2007-03-07';
