/*
    The PostgreSQL ROLLUP is a subclause of the GROUP BY clause that offers a
    shorthand for defining multiple grouping sets.

    Different from the CUBE subclause, ROLLUP does not generate all possible grouping
    sets based on the specified columns. It just makes a subset of those.

    The ROLLUP assumes a hierarchy among the input columns and generates all grouping
    sets that make sense considering the hierarchy.
*/

SELECT
    segment,
    brand,
    SUM (quantity)
FROM
    sales
GROUP BY
    ROLLUP (segment, brand)
ORDER BY
    segment,
    brand;


SELECT
    EXTRACT (YEAR FROM rental_date) y,
    EXTRACT (MONTH FROM rental_date) M,
    EXTRACT (DAY FROM rental_date) d,
    COUNT (rental_id)
FROM
    rental
GROUP BY
    ROLLUP (
        EXTRACT (YEAR FROM rental_date),
        EXTRACT (MONTH FROM rental_date),
        EXTRACT (DAY FROM rental_date)
    );
