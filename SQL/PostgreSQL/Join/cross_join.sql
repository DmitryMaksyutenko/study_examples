/*
    A CROSS JOIN clause allows to produce the Cartesian Product of rows in two or more tables.
    Different from the other JOIN operators such as LEFT JOIN  or INNER JOIN,
    the CROSS JOIN does not have any matching condition in the join clause.

    SELECT
        *
    FROM
        T1
    CROSS JOIN T2;

    SELECT
        *
    FROM
        T1, T2;

    SELECT
        *
    FROM
        T1
    INNER JOIN T2 ON TRUE;
*/


SELECT
    a1.actor_id,
    a1.first_name,
    a2.actor_id,
    a2.first_name
FROM
    actor a1
CROSS JOIN actor a2;

