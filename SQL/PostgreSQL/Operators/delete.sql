/*
    For delete data from the table use the DELETE satatement.

    DELETE FROM table
    WHERE condition;

    The DELETE statement returns the number of deleted rows.

    In case to check the condition that references to one or more columns in another table,
    use the USING clause or subquery.
*/

DELETE FROM rental
WHERE rental_id = 1;
