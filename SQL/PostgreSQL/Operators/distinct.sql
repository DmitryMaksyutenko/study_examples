/*
  The DISTINCT clause is used in the SELECT statement to remove duplicate rows.
*/

-- Create test table.
CREATE TABLE t1 (
  id serial NOT NULL primary key,
  bcolor VARCHAR,
  fcolor VARCHAR
);

-- Add some rows into table t1.
INSERT INTO t1 (bcolor, fcolor)
VALUES
  ('red', 'red'),
  ('red', 'red'),
  ('red', 'NULL'),
  ('red', 'red'),
  ('NULL', 'red'),
  ('red', 'green'),
  ('red', 'blue'),
  ('green', 'red'),
  ('green', 'blue'),
  ('green', 'green'),
  ('blue', 'blue'),
  ('blue', 'green'),
  ('blue', 'green'),
  ('blue', 'blue');

-- Shows all with duplicates
SELECT
  id,
  bcolor,
  fcolor
FROM
  t1;

-- Shows bcolor witout duplicates
SELECT
  DISTINCT bcolor
FROM
 t1;

-- DISTINCT om multiple columns.
SELECT
  DISTINCT bcolor,
            fcolor
FROM
  t1;

SELECT
  DISTINCT ON
    (bcolor) bcolor,
    fcolor
FROM
  t1;

DROP TABLE t1;
