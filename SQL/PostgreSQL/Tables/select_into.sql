/*
  The PostgreSQL SELECT INTO statement creates a new table and inserts data returned
  from a query into the table.

  The new table will have columns with the names the same as columns of the result
  set of the query. Unlike a regular SELECT statement, the SELECT INTO statement does
  not return a result to the client

    SELECT
        select_list
    INTO [ TEMPORARY | TEMP | UNLOGGED  ] [ TABLE  ] new_table_name
    FROM
        table_name
    WHERE
      search_condition;

  Besides the WHERE clause, can use other clauses in the SELECT statement
  for the SELECT INTO statement such as INNER JOIN, LEFT JOIN, GROUP BY, and HAVING.
*/

SELECT
  film_id,
  title,
  rental_rate
INTO TABLE film_r
FROM
  film
WHERE
  rating = 'R'
AND rental_duration = 5
ORDER BY
title;

SELECT * FROM film_r;
DROP TABLE film_r;

SELECT
  title,
  length
INTO TEMPORARY TABLE test_film
FROM
  film
WHERE
  length < 60
ORDER BY title;

SELECT * FROM test_film;
