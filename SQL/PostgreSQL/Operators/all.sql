/*
    The PostgreSQL ALL operator allows  to query data by comparing a value with a list of values returned by a subquery.
*/

SELECT
    film_id,
    title,
    length
FROM
    film
WHERE
    length > ALL (
        SELECT
            ROUND(AVG (length),2)
        FROM
            film
        GROUP BY
            rating
        )
ORDER BY
    length;
