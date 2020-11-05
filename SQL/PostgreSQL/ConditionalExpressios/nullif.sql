/*
    The NULLIF function returns a NULL value if value1 equals value2, otherwise it returns value1,

        NULLIF(value1, value2)

    This can be used to perform the inverse operation ot the COLAESCE.
*/

SELECT NULLIF('yes', 'no'); -- yes
SELECT NULLIF('no', NULL); -- no
SELECT NULLIF(NULL, 'none'); -- NULL
SELECT NULLIF(NULL, 0); -- NULL
SELECT NULLIF('no', 'no'); -- NULL

-- Took time 128.206 ms
SELECT
    first_name,
    last_name,
    title
FROM
    actor,
    film,
    film_actor
WHERE
    NULLIF(film_actor.actor_id, actor.actor_id) IS NULL 
    AND
    NULLIF(film_actor.film_id, film.film_id) IS NULL 
ORDER BY
    last_name;


-- Took time 7.736 ms
SELECT
    first_name,
    last_name,
    title
FROM
    actor,
    film,
    film_actor
WHERE
    film_actor.actor_id = actor.actor_id AND
    film_actor.film_id = film.film_id;