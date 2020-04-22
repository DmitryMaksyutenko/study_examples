/*
  A composite type represents the structure of a row or record.
  It's essentialy just a list of filed names and their data types.

  CREATE TYPE name AS [ expression ];
*/

CREATE TYPE film_summary AS (
  fild_id INT,
  title VARCHAR,
  release_year YEAR
);

-- Creates function for testing.
CREATE OR REPLACE FUNCTION get_film_summary (f_id INT)
  RETURNS film_summary AS
$$
  SELECT
    film_id,
    title,
    release_year
  FROM
    film
  WHERE
    film_id = f_id;
$$
LANGUAGE SQL;

-- Test query.
SELECT
  *
FROM
  get_film_summary(40);

-- Type and function removing.
DROP FUNCTION get_film_summary;
DROP TYPE film_summary;
