/*
    The PostgreSQL ANY operator compares a value to a set of values returned by a subquery.

    Note that SOME is a synonym for ANY
*/

SELECT
    MAX( length  )
FROM
    film
INNER JOIN film_category
    USING(film_id)
GROUP BY
    category_id;


SELECT title
FROM film
WHERE length >= ANY(
    SELECT MAX( length  )
    FROM film
    INNER JOIN film_category USING(film_id)
    GROUP BY  category_id 
);


-- ANY as equivalent IN.
SELECT
    title,
    category_id
FROM
    film
INNER JOIN film_category
    USING(film_id)
WHERE
    category_id = ANY(
        SELECT
            category_id
        FROM
            category
        WHERE
            NAME = 'Action'
            OR NAME = 'Drama'
    );
