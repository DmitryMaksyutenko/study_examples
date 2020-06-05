/*
    PostgreSQL CUBE is a subclause of the GROUP BY clause. The CUBE allows to generate
    multiple grouping sets.
*/


SELECT
    brand,
    segment,
    SUM (quantity)
FROM
    sales
GROUP BY
    CUBE (brand, segment)
ORDER BY
    brand,
    segment;
