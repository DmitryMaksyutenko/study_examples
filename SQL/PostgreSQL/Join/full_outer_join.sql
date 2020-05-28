SELECT
    a.id id_a,
    a.fruit fruit_a,
    b.id id_b,
    b.fruit fruit_b
FROM
    basket_a a
FULL OUTER JOIN basket_b b ON
    a.fruit = b.fruit;


SELECT
    a.id id_a,
    a.fruit fruit_a,
    b.id id_b,
    b.fruit fruit_b
FROM
    basket_a a
FULL JOIN basket_b b ON
    a.fruit = b.fruit
    WHERE a.id IS NULL OR b.id IS NULL;


-- JOIN with foreign key.
SELECT
    actor.actor_id,
    actor.first_name,
    actor.last_name,
    LEFT(film_info, 150) film_info
FROM
    actor
FULL OUTER JOIN actor_info ON
    actor.actor_id = actor_info.actor_id;
