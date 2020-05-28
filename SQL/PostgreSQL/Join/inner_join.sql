SELECT
    a.id id_a,
    a.fruit fruit_a,
    b.id id_b,
    b.fruit fruit_b
FROM
    basket_a a
INNER JOIN basket_b b ON
    a.fruit = b.fruit;


-- Using Foreign key.
SELECT
    customer.customer_id,
    first_name,
    last_name,
    email,
    amount,
    payment_date
FROM
    customer
INNER JOIN payment ON
    payment.customer_id = customer.customer_id;


-- Join with three tables.
SELECT
    customer.customer_id,
    customer.first_name customer_first_name,
    customer.last_name customer_last_name,
    customer.email,
    staff.first_name staff_first_name,
    staff.last_name staff_last_name,
    amount,
    payment_date
FROM
    customer
INNER JOIN payment ON
    payment.customer_id = customer.customer_id
INNER JOIN staff ON
    payment.staff_id = staff.staff_id;
