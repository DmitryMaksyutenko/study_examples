/*
    Aggregate functions compute a single result from a set of input values.

    Standard SQL’s aggregate functions:

    AVG() – return the average value.
    COUNT() – return the number of values.
    MAX() – return the maximum value.
    MIN() – return the minimum value.
    SUM() – return the sum of all or distinct values.

    The aggregate functions offten used with GROUP BY clause in the SELECT statement
    and HAVING clause.

*/


SELECT
    ROUND(AVG( replacement_cost), 2) avg_replacement_cost
FROM
    film;


SELECT
    ROUND( AVG( replacement_cost  ), 2  ) avg_replacement_cost
FROM
    film
INNER JOIN film_category USING(film_id)
INNER JOIN category USING(category_id)
WHERE
    category_id = 7;
