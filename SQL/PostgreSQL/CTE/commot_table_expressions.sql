/*
  The CTE - common table expressions. It's a tool for sequential queries execution on PostgreSQL.
  The CTE allows define subquery once, set the name to it, and use many times is the main query.
  The CTE helps to organize the SQL code.

  WITH <subquery name> AS (<subquery code>) [, ...]
  SELECT <Select list> FROM <subquery name>;

  In fact, the PostgreSQL executes CTE once, cache it result, and reuse.
*/

WITH custumers AS
    (SELECT first_name, address_id, last_update FROM customer WHERE last_update > '2013-05-25'),
    addr AS
    (SELECT address, address.address_id FROM custumers
        INNER JOIN address ON address.address_id = custumers.address_id)
SELECT
    addr.address, name, last_update
FROM addr INNER JOIN customer_list
    ON customer_list.address = addr.address
    INNER JOIN custumers
    ON custumers.address_id = addr.address_id;

