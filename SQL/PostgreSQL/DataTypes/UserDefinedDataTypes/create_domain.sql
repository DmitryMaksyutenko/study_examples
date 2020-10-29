/*
  A domain is a user-defined type based on another underlying type (other user-defined,
  enum, base type...).

  CREATE DOMAIN - creates a user-defined type with constrains such as NOT NULL, CHECK, etc.
  Has a unique name within the shcema scope.

  Domains are useful for centralizing management of fields with the common constrains.

  CREATE DOMAIN name [ AS ] data_type
    [ COLLATE collation ]
    [ DEFAULT expression ]
    [ constraint [ ... ] ]

  where constraint is:
    [ CONSTRAINT constraint_name ]
    { NOT NULL | NULL | CHECK (expression) }
*/


-- Creating the table with checking for varchar fields.
-- Without user-defined domain.
CREATE TABLE mail_list (
  id SERIAL PRIMARY KEY,
  first_name VARCHAR NOT NULL,
  last_name VARCHAR NOT NULL,
  email VARCHAR NOT NULL
CHECK(
  first_name !~ '\s'
  AND
  last_name !~ '\s'
));


-- Creating domain.
CREATE DOMAIN contact_name AS
  VARCHAR NOT NULL CHECK (value !~ '\s');

-- Creating table with the user-defined type contact_name.
CREATE TABLE mail_list (
  id SERIAL PRIMARY KEY,
  first_name contact_name,
  last_name contact_name,
  email VARCHAR NOT NULL
);

-- Removing table and user-defined type.
DROP TABLE mail_list;
DROP DOMAIN contact_name;
