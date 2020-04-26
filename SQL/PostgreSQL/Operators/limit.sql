/*
  The LIMIT clause is not a SQL-standard.


  LIMIT is an optional clause of the SELECT statement that returns a subset of
  rows returned by the query.

  [ LIMIT { number | ALL } ] [ OFFSET number ]

  OFFSET skips a number of rows before returning LIMIT number.

  Use with ORDER BY to control the row order.
*/

-- Base example.
SELECT
  film_id,
  title,
  release_year
FROM
  film
ORDER BY
  film_id
LIMIT 5;

-- With offset.
SELECT
  film_id,
  title,
  release_year
FROM
  film
ORDER BY
  film_id
LIMIT 5 OFFSET 10;

-- Moust 15 expensive films.
SELECT
  film_id,
  title,
  rental_rate
FROM
  film
ORDER BY
  rental_rate DESC
LIMIT 15;
