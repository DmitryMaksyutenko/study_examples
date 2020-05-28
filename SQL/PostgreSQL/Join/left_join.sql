SELECT
    a.id id_a,
    a.fruit fruit_a,
    b.id id_b,
    b.fruit fruit_b
FROM
    basket_a a
LEFT JOIN basket_b b ON
    a.fruit = b.fruit;


SELECT
    a.id id_a,
    a.fruit fruit_a,
    b.id id_b,
    b.fruit fruit_b
FROM
    basket_a a
LEFT JOIN basket_b b ON
    a.fruit = b.fruit
    WHERE b.id IS NULL;


-- LEFT JOIN with foreign key.
SELECT
    film.film_id,
    film.title,
    inventory_id
FROM
    film
LEFT JOIN inventory ON
    inventory.film_id = film.film_id;
