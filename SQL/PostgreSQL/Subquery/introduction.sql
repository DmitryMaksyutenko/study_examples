/*
  The subquery is the query nested inside the other query. Also, it's can be called an internal query.
  Mostly used with FROM clause as the source of the data for main query.
  A scalar subqueries may be used in any expression (In PostgreSQL).
  There is no access to elements inside the subquery, but the subquery can use elements from the main
  query (external elements).
*/

SELECT
  film_id,
  title,
  rental_rate
FROM
  film
WHERE
  rental_rate > (
                  SELECT
                    AVG(rental_rate)
                  FROM
                    film
                )
ORDER BY
  film_id;
