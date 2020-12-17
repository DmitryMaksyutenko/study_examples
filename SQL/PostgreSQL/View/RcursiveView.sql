/*
    The recursive view is a syntax sugar that uses the recursive CTE inside the view definition.

        CREATE RECURSIVE VIEW view_name(columns) AS
        SELECT columns;

        Same:

        CREATE VIEW view_name 
        AS
        WITH RECURSIVE cte_name (columns) AS (
            SELECT ...)
        SELECT columns FROM cte_name;
*/

CREATE RECURSIVE VIEW reporting_line (employee_id, subordinates) AS 
SELECT
	employee_id,
	full_name AS subordinates
FROM
	employees
WHERE
	manager_id IS NULL
UNION ALL
	SELECT
		e.employee_id,
		(
			rl.subordinates || ' > ' || e.full_name
		) AS subordinates
	FROM
		employees e
	INNER JOIN reporting_line rl ON e.manager_id = rl.employee_id;