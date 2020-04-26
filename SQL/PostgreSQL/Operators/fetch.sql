/*
  The LIMIT clause is not a SQL-standard.

  FETCH — retrieve rows from a query using a cursor.

  OFFSET start { ROW | ROWS }
  FETCH [ direction [ FROM | IN ] ] cursor_name

  where direction can be empty or one of:

      NEXT
      PRIOR
      FIRST
      LAST
      ABSOLUTE count
      RELATIVE count
      count
      ALL
      FORWARD
      FORWARD count
      FORWARD ALL
      BACKWARD
      BACKWARD count
      BACKWARD ALL

  FETCH { FIRST | NEXT } [ row_count ] { ROW | ROWS } ONLY
*/

SELECT
  film_id,
  title
FROM
  film
FETCH FIRST ROW ONLY;

SELECT
  film_id,
  title
FROM
  film
ORDER BY
  title DESC
FETCH FIRST 10 ROW ONLY;

SELECT
  film_id,
  title
FROM
  film
ORDER BY
  title ASC
OFFSET 10
FETCH FIRST 10 ROW ONLY;
