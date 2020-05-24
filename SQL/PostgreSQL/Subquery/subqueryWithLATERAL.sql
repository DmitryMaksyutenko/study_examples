/*
    The LATERAL key word can precede a sub-SELECT FROM item. This allows the sub-SELECT
    to refer to columns of FROM items that appear before it in the FROM list.
    (Without LATERAL, each sub-SELECT is evaluated independently and so cannot cross-reference
    any other FROM item.)
*/

SELECT
    actor_id,
    first_name,
    last_name,
    CASE
        WHEN first_name IN
            (
                SELECT
                    first_name
                FROM
                    actor
                WHERE
                    first_name LIKE 'Ca%'
            )
        THEN 'in' ELSE 'not in' END AS in_name_count,
        (
            SELECT
               char_length(first_name)
            FROM
                actor
            WHERE
                actor.actor_id = c.actor_id
        ) AS name_length
FROM
    actor AS c
WHERE
    first_name LIKE 'C%';


-- The lateral subquery
SELECT
    actor_id,
    first_name,
    last_name,
    CASE
        WHEN first_name IN
            (
                SELECT
                    first_name
                FROM
                    actor
                WHERE
                    first_name LIKE 'Ca%'
            )
        THEN 'in' ELSE 'not in' END AS in_name_count,
        name_length
FROM
    actor AS c,
    LATERAL
    (
        SELECT
            char_length(first_name)
        FROM
            actor
        WHERE
            actor.actor_id = c.actor_id
    ) name_length
WHERE
    first_name LIKE 'C%';
