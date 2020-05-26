/*
    A PostgreSQL alias assigns a temporary name to table or column
    during query executeion,

    Table alias:
        FROM table_reference AS alias;
        or
        FROM table_reference alias;

    Column alias:
        SELECT column_name AS alias FROM table;
        or
        SELECT column_name alias FROM table;
*/

-- Column alias
SELECT
    first_name || ' ' || last_name AS full_name
FROM
    customer
ORDER BY
    full_name;


-- Table alias
SELECT
    *
FROM
    actor AS alias_name;

SELECT
    a.first_name,
    f.title
FROM
    actor a,
    film f,
    film_actor
WHERE
    a.actor_id = film_actor.actor_id AND
    f.film_id = film_actor.film_id;
