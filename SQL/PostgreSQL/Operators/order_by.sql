/*
  The ORDER BY clause allows to sort rows returned from SELECT statement in
  ascending or descending order based on the specified criteria.

  [WITH with_queries] SELECT slect_list FROM table_expression [sort_expression]

  SELECT
    select_list
  FROM 
    table_expression
  ORDER BY
    sort_expression1 [ASC | DESC] [NULLS {FIRST | LAST}]                    specifies the sort order.
            [, sort_expression2 [ASC | DESC] [NULLS {FIRST | LAST}] ...]

  After a query has produced an output table (after the SELECT list has been processed)
  it can optionaly be sorted.

  Note that the SQL standard only allows to sort rows based on the columns that appear in
  the SELECT clause. However, PostgreSQL allow to sort rows based on the columns that even
  does not appear in the selection list.

  USE SQL STANDART! IT'S A GOOD PRACTICE.

 */

-- Sort by the first_name in ascending order.
SELECT
  customer_id, first_name, last_name, email
FROM
  customer
  ORDER BY first_name ASC;

-- Get customers count.
SELECT
  count(customer_id)
FROM
  customer;

-- Sort by the last_name in descending order.
SELECT
  first_name,
  last_name,
  email
FROM
  customer
ORDER BY
  last_name DESC;

-- Sort last_name in ascending order and then first_name in descending order.
SELECT
  customer_id,
  first_name,
  last_name
FROM
  customer
ORDER BY
  first_name ASC,
  last_name DESC;

-- Sort row by expression.
SELECT
  customer_id,
  first_name,
  last_name,
  length(last_name) AS len
FROM
  customer
ORDER BY
  length(last_name) DESC;
