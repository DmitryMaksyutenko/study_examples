/*
    In relational databases, the term upsert is referred to as a merge.
    The idea is that when insert a new row into the table, PostgreSQL will update the row
    if it already exists, otherwise, PostgreSQL inserts the new row.
    That is why we call the action is upsert (update or insert).

    To use the upsert feature in PostgreSQL, use the INSERT ON CONFLICT statement as follows:

        INSERT INTO table_name(column_list) VALUES(value_list)
        ON CONFLICT target action;

    The target can be:

        (column_name) – a column name.

        ON CONSTRAINT constraint_name – where the constraint name could be
        a name of the UNIQUE constraint.

        WHERE predicate – a WHERE clause with a predicate

    The action can be:

        DO NOTHING – means do nothing if the row already exists in the table.

        DO UPDATE SET column_1 = value_1, .. WHERE condition – update some fields in the table.
*/

CREATE TABLE customers (
    customer_id serial PRIMARY KEY,
    name VARCHAR UNIQUE,
    email VARCHAR NOT NULL,
    active bool NOT NULL DEFAULT TRUE
);

DROP TABLE IF EXISTS customers;


INSERT INTO
    customers (NAME, email)
VALUES
    (
        'IBM',
        'contact@ibm.com'
    ),
    (
        'Microsoft',
        'contact@microsoft.com'
    ),
    (
        'Intel',
        'contact@intel.com'
    );


INSERT INTO
    customers (NAME, email)
VALUES
    (
        'Microsoft',
        'hotline@microsoft.com'
    )
ON CONFLICT ON CONSTRAINT customers_name_key 
DO NOTHING;


INSERT INTO
    customers (name, email)
VALUES
(
    'Microsoft',
    'hotline@microsoft.com'
)
ON CONFLICT (name)
DO
    UPDATE
      SET email = EXCLUDED.email || ';' || customers.email;
