/*
  An index is a separated data structure e.g. B-tree that speeds up the data
  retrieval on a table at the cost of additional writes and storage to
  maintain it.

  CREATE [ UNIQUE ] INDEX [ CONCURRENTLY ] [ [ IF NO EXISTS ] name ] ON table_name
  [ USING method ] ({ column_name | (expression) }
  [ COLLATE collation ] [ opclass ] [ ASC | DESC ]
  [ NULLS { FIRST | LAST } ] [, ...])
  [WITH (storage_parameter = value [, ...])]
  [TABLESPACE tablespace_name]
  [WHERE predicate];
*/

CREATE INDEX idx_address_phone
ON
  address(phone);

-- Shows different results on a column with index and without.
EXPLAIN
SELECT
  *
FROM
  address
WHERE
  phone = '223664661973';
