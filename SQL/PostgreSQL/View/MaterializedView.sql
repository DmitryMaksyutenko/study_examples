/*
  PostgreSQL extends the view to the next level that allowd to store data
  phisically in the view. It's named materialized view.
  Materialized view cahced the result of a complex expensive query and then
  allow to refresh this result.

  CREATE MATERIALIZED VIEW [ IF NOT EXISTS ] table_name
    [ (column_name [, ...]) ]
    [ WITH (storege_paremeter [= value] [, ...]) ]
    [ TABLESPACE tablespace_name ]
    [ WITH [ NO ] DATA ]

  Data can be loaded or not. For loading data in creation time use
  the WITH DATA option. Or use WITH NO DATA insted.

  Materialized view may be refreshed to upload data with
  REFRESH MATERIALIZED VIE view_name; statement.

  Removing the materialized view.
  DROP MATERIALIZED VIEW view_name;
*/

CREATE MATERIALIZED VIEW test_mat AS
SELECT 1
WITH NO DATA;

TABLE test_mat; -- ERROR:  materialized view "test_mat" has not been populated.

REFRESH MATERIALIZED VIEW test_mat;

TABLE test_mat; -- Return 1.

DROP MATERIALIZED VIEW test_mat;
