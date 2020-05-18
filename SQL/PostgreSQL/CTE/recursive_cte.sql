/*
    WITH RECURSIVE <subquery_name> (<field list>) AS
    (
    <non-recursive term>
    UNION [ALL|DISTINCT]
    <recursive term>

    )
    [,...]
    <main query>
*/

WITH RECURSIVE fact (n, f) AS
(
    SELECT 1, 1
    UNION ALL
    SELECT n + 1, f * (n + 1) FROM fact WHERE n < 5
)
SELECT * FROM fact;
