/*
  Used in WGERE clause to check if a value matces any value in a list of values.

  value IN (value1, value2, ...)

  The expression returns true if the value matches any value in the list.
  The list of values can be a list of numbers or strings or the result
  of a SELECT statement.

  The query with IN is more readabele then the queries with the operators
  = and OR. And IN is works faster.

  The IN operator can be combined with the NOT operator, to select the rows
  whose values do not match the values in the list.
*/

-- Show name and surname of the customers with ID 1, 2, 3.
SELECT
  first_name,
  last_name
FROM
  customer
WHERE
  customer_id IN (
    1, 2, 3
);

-- Show rental information of users with ID 1, 2.
SELECT
  customer_id,
  rental_id,
  rental_date
FROM
  rental
WHERE
  customer_id IN (
    1, 2
)
ORDER BY
  return_date DESC;

-- Shows every person's name whose id not even number.
SELECT
  customer_id,
  first_name
FROM
  customer
WHERE
  customer_id NOT IN
  (
    SELECT
     customer_id
    FROM
     customer
    WHERE
     customer_id % 2 = 0
  )
ORDER BY
  customer_id;
