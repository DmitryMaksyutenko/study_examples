/*
  If a subquery returns any row, the EXISTS operator return true.

  EXISTS (SELECT 1 FROM table WHERE condition);
*/

SELECT
  first_name,
  last_name
FROM
  customer
WHERE
  EXISTS (
            SELECT
              1
            FROM
              payment
            WHERE
              payment.customer_id = customer.customer_id
         );
