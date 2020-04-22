/*
  After the FROM clause processing is done, each row of the derived virtual table is
  checked against the search condition.

  WHERE search_condition.

  The condition must evaluate to true, false or unknown. It can be a Boolean expression
  or a combination of Boolean expressions.
*/

-- Where with = operator.
SELECT
  last_name,
  first_name
FROM
  customer
WHERE
  first_name = 'Jamie';

-- Where with AND operator.
SELECT
  first_name,
  last_name
FROM
  customer
WHERE
  last_name = 'Rice'
AND
  first_name = 'Jamie';

-- Where with OR operator.
SELECT
  first_name,
  last_name
FROM
  customer
WHERE
  last_name = 'Rodriguez'
OR
  first_name = 'Adam';

-- Where with IN operator.
SELECT
  last_name,
  first_name
FROM
  customer
WHERE
  first_name
IN('Ann',
  'Anne',
  'Annie');

-- Where with LIKE operator.
SELECT
  first_name,
  last_name
FROM
  customer
WHERE
  first_name
LIKE
  'Ann%';

-- Where with BETWEEN operator.
SELECT
  first_name,
  last_name
FROM
 customer
WHERE
 first_name
LIKE
  'A%'
AND
length(first_name) BETWEEN 3 AND 5;

-- Where with <> operator.
SELECT
  first_name,
  last_name
FROM
  customer
WHERE
  first_name
LIKE
  'Bra%'
AND
  last_name <> 'Motley';
