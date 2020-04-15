/*
  CHECK OPTION may not be used with RECURSIVE views.

  Only sopportd on views that are automaticali updatable, and do not have
  INSTED OF trigger or INSTED rules except view is defined on top of a
  base view that has INSTED OF.
*/

CREATE VIEW usa_city AS
SELECT
  city_id,
  city,
  country_id
FROM
  city
WHERE
  country_id = 103
ORDER BY
  city;

-- Next queries can insert new rows in a table.
INSERT INTO usa_city (
  city,
  country_id)
VALUES (
  'Birningham',
  102);

INSERT INTO usa_city (
  city,
  country_id)
VALUES (
  'Cambridge',
  102);

-- Replace view usa_city with check option.
CREATE OR REPLACE VIEW usa_city AS
SELECT
  city_id,
  city,
  country_id
FROM
  city
WHERE
  country_id = 103
ORDER BY
  city
WITH CHECK OPTION;
