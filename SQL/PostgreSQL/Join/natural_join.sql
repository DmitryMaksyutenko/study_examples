/*
    A natural join is a join that creates an implicit join based on the same
    column names in the joined tables.

    The convenience of the NATURAL JOIN is that it does not require to specify
    the join clause because it uses an implicit join clause based on the common column.

    However, avoid using the NATURAL JOIN whenever possible because sometimes
    it may cause an unexpected result.

    SELECT
        *
    FROM
        T1
    NATURAL [INNER, LEFT, RIGHT] JOIN T2;
*/

-- The unexpected behaviour.
-- Returns 0 rows because second common column named 'last_update'.
SELECT
    *
FROM
    city
NATURAL JOIN country;


SELECT
    *
FROM
    city
INNER JOIN country ON
    city.last_update = country.last_update;



-- Correct query.
SELECT
    *
FROM
    city
INNER JOIN country ON
    city.country_id = country.country_id;
