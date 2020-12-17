/*
  Views in PostgreSQL are implemented using the rule system.

  A view is named query stored in database or
  that provides another way to present data in the database tables.

  It's a databse object that can be accessed as a virtual table in
  PostgreSQL. In othre words it is a logical table that represents
  data of one or more underlying tables through a SELECT statement.

  NOTE that a view does not store data physically except
  for materialized view.

  Creating VIEW:
  CREATE [ OR REPLACE ] [ TEMP | TEMPORARY ] [ RECURSIVE ] VIEW name [ (clumn_name [, ...]) ]
    [ WITH (view_option_name [= view_option_value] [, ...]) ]
    AS query
    [ WITH [ CASCADED | LOCAL ] CHECK OPTION ];

  Removing VIEW:
  DROP VIEW [ IF EXISTS ] view_name;
*/

-- Createing VIEW for car_portal table account for retrieving all info except
-- the password.
CREATE VIEW account_information AS
SELECT
  account_id,
  first_name,
  last_name,
  email
FROM
  account;

-- tru to change VIEW.
CREATE OR REPLACE VIEW account_information AS
SELECT
  account_id, -- ERROR
  last_name,
  first_name,
  email
FROM
  account;

-- Try to draop unexisting VIEW
DROP VIEW IF EXISTS some_view; -- No ERROR.
DROP VIEW some_view; -- ERROR result.
