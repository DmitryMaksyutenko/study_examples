/*
  The EXCEPT operator returns rows by comparing the result of sets of
  two or more queries.

  The EXISTS operator returns distinct rows from the first(left) query
  that are not in the output of the second(right) quety.

  The order and the number of columns in queries must be the same.
  The data type of respective columns must be compatible.
 */

 SELECT
  film_id,
  title
FROM
  film
EXCEPT
SELECT DISTINCT
  inventory.film_id,
  title
FROM
  inventory
INNER JOIN film ON film.film_id = inventory.film_id
ORDER BY
  title;
