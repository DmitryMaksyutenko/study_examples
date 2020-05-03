/*
  the UNION operator combines result sets of two or more queries,
  into one single result set.

  -The queries must return the same numbers of columns.
  -The corresponding coulumns in the queries must have compatable data types.

  The UNION operator removes all duplicate rows unless the UNION ALL is used.

  The UNION operator ofen used to combine data from similar tables that are not
  perfectly normalized.
*/

SELECT
  10, 11, 12
UNION
SELECT
  1, 2, 3;


-- Returns 200 rows.
SELECT
	actor_id
FROM
	actor
UNION
SELECT
	actor_id
FROM
	film_actor
ORDER BY
	actor_id;


-- Returns 5662 rows.
SELECT
	actor_id
FROM
	actor
UNION
SELECT
	actor_id
FROM
	film_actor
ORDER BY
	actor_id;

-- Returns 1200 rows.
SELECT
	film_id,
	title
FROM
	film
UNION
SELECT
	actor_id,
	last_name
FROM
	actor
WHERE 
actor_id IN (
SELECT
	actor_id
FROM
	film_actor, film
WHERE
	film.film_id = film_actor.film_id
)
ORDER BY
	film_id; 
