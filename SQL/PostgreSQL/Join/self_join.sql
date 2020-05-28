/*
    A self-join is a query in which a table is joined to itself.
    Self-joins are useful for comparing values in a column of rows within the same table.

    To form a self-join, specify the same table twice with different aliases,
    set up the comparison, and eliminate cases where a value would be equal to itself.
*/

SELECT
    a1.first_name,
    a1.last_name,
    a2.last_update
FROM
    actor a1
INNER JOIN  actor a2 ON
    a1.actor_id = a2.actor_id;



-- Get films with the same length.
SELECT
    f1.title,
    f2.title,
    f1. length
FROM
    film f1
INNER JOIN film f2 ON
    f1.film_id <> f2.film_id
    AND f1. length = f2. length
ORDER BY f1.title;
