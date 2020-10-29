/*
    The CASE expression is the same as IF/ELSE statement in other programming
    languages. It allows to add if-else logic to the query tu form a powerful
    query.

    Since CASE is an expression, it can be userd in any place where an expression
    can be used:
        SELECT, WHERE GROUP BY, HAVING.

    Has two forms:

        CASE
            WHEN condition_1 THEN result_1
            WHEN condition_2 THEN result_2
            [WHEN ...]
            [ELESE else_result]
        END

        Second is using CASE with an aggreagate functions.

        SUM(CASE
                WHEN conditin
                THEN result
                ELSE else_result
            END) AS alias_name
*/


SELECT
    first_name,
    last_name
FROM
    actor
WHERE
    CASE
        WHEN LENGTH(first_name) < 5
        THEN true
    END;


SELECT
    ROUND(AVG(LENGTH(first_name))) AS avg_name_len
FROM
    actor;


SELECT
    SUM(CASE
            WHEN LENGTH(first_name) = 3
            THEN 1
            END) AS "len_3",
    SUM(CASE
            WHEN LENGTH(first_name) = 4
            THEN 1
            END) AS "len_4",
    SUM(CASE
            WHEN LENGTH(first_name) = 5
            THEN 1
            END) AS "len_5"
FROM
    actor;
