/*
    In the database world, NULL means missing information or not applicable. NULL is not a value,
    therefore, it cannot be compare with any value like a number or a string. The comparison of
    NULL with a value will always result in NULL, which means an unknown result.
*/

SELECT
    *
FROM
    address
WHERE
    postal_code IS NULL;
