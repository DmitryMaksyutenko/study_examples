/*
     A primary key is a column or a group of columns used to identify a row uniquely in a table.

    Define primary keys through primary key constraints. Technically, a primary key constraint is the combination of a not-null constraint
    and a UNIQUE constraint.

    A table can have one and only one primary key. It is a good practice to add a primary key to every table. When add a primary key to a table,
    PostgreSQL creates a unique B-tree index on the column or a group of columns used to define the primary key.

        CREATE TABLE TABLE (
            column_1 data_type PRIMARY KEY,
            column_2 data_type,
            …
        );

    In case the primary key consists of two or more columns, define the primary key constraint as:

        CREATE TABLE TABLE (
            column_1 data_type,
            column_2 data_type,
            … 
                PRIMARY KEY (column_1, column_2)
        );

    If don’t specify explicitly the name for primary key constraint, PostgreSQL will assign a default name to the primary key constraint.
    By default, PostgreSQL uses table-name_pkey as the default name for the primary key constraint. In this example, PostgreSQL creates the
    primary key constraint with the name po_items_pkey for the po_items table.

    In case to specify the name of the primary key constraint, use CONSTRAINT clause as follows:

        CONSTRAINT constraint_name PRIMARY KEY(column_1, column_2,...);

    It is rare to define a primary key for existing table. In case have to do it, use the ALTER TABLE statement to add a primary key constraint.

        ALTER TABLE table_name ADD PRIMARY KEY (column_1, column_2);

        ALTER TABLE table_name ADD COLUMN id SERIAL PRIMARY KEY;

    Drop the primary key.

        ALTER TABLE table_name DROP CONSTRAINT primary_key_constraint;
*/

CREATE TABLE test_table (
    column_1 INT,
    column_2 CHAR(1),
    column_3 TIME DEFAULT current_time
);


INSERT INTO
    test_table
VALUES
    (14, 'q'),
    (34, 'e'),
    (37, 'a'),
    (42, 's'),
    (22, 'r'),
    (33, 't'),
    (41, 'k'),
    (24, 'o');


ALTER TABLE test_table
ADD COLUMN id SERIAL PRIMARY KEY;


ALTER TABLE test_table
DROP CONSTRAINT test_table_pkey;


DROP TABLE IF EXISTS test_table;
