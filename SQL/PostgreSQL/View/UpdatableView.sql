/*
  The Postgres view is updatable when it meets the following conditions:

  - The defining query of the view must have exactly one enty in the
    FROM clause, which can be a table of another updatable view.

  - The defining quety must not contain one ot the following clauses
    at the top level:
    GROUP BY
    HAVING
    LIMIT
    OFFSET
    DISTINCT
    WITH
    UNION
    INTERSECT
    EXCEPT

  - the selection list must not contain any functions.

  The updatable view can contain both updatable and not updatable
  columns. Try to insert or update a non-updatable column, will
  raise an ERROR.
*/

CREATE VIEW account_full_name AS
SELECT
  first_name,
  last_name
FROM
  account;

-- Add account_id for selection.
CREATE OR REPLACE VIEW account_full_name AS
SELECT
  first_name,
  last_name,
  account_id
FROM
  account;

-- Update the first_name and last_name in account with id equal 2.
UPDATE account_full_name
SET
  first_name = 'Name',
  last_name = 'Surname'
WHERE
  account_id = 2;

-- ERROR:  null value in column "email" violates not-null constraint.
INSERT INTO account_full_name
VALUES (
  'Newname',
  'Newlastname',
  3
);

INSERT INTO account
VALUES(
  3,
  'Joe',
  'Foo',
  'email@foo.com',
  'passwort1234'
);

-- Update only last_name column in row with id equal 3.
UPDATE account_full_name
SET
  last_name = 'Moll'
WHERE
  account_id = 3;

-- User account view
CREATE VIEW user_account AS
SELECT
  account_id,
  first_name,
  last_name,
  email,
  password
FROM
  account
WHERE
account_id NOT IN (
  SELECT
    account_id
  FROM
    seller_account
);

--Insert come values via user_account view.
INSERT INTO user_account
VALUES (
  default,
  'first_name1',
  'last_name1',
  'test@mail.com',
  'somepassword'
);

--Insert into account with account of seller.
WITH account_info AS (
  INSERT INTO user_account
  VALUES (
  default,
  'first_name2',
  'last_name2',
  'test2@mail.com',
  'somepassword2')
  RETURNING account_id)
INSERT INTO seller_account (
  account_id,
  number_of_advertizement,
  user_ranking,
  total_rank)
SELECT
  account_id,
  1,
  1.1,
  1.1
FROM
  account_info;
