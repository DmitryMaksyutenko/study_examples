/*
    The GROUP BY Clause is used to group together those rows in a table
    that have the same values in all the columns listed.

    The GROUP BY clause must appear right after the FROM or WHERE clause.
    Following the GROUP BY clause is one column or a list of comma-separated columns.

    SELECT
        select_list
    FROM
        ...
    [WHERE ...]
    GROUP BY grouping_column_reference [, grouping_column_reference]...
*/

SELECT
   customer_id
FROM
   payment
GROUP BY
   customer_id;

SELECT
    customer_id,
    AVG(amount) AS average,
    SUM(amount) AS summa
FROM
    payment
GROUP BY
    customer_id
ORDER BY
    customer_id;
