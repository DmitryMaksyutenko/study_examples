/*
    To control wether the column can accept NULL, used NOT NULL constraint.

    If the column has the NOT NULL constraint, then attempt to insert or update the value to NULL will cause to error raising.
*/

-- NOT NULL it a table creation expression.
CREATE TABLE test_table_1 (
    id SERIAL PRIMARY KEY NOT NULL,
    column_1 CHAR(1) NOT NULL,
    column_2 CHAR(1) NOT NULL CHECK (column_2 <> 'a')
);

-- Error
INSERT INTO
    test_table_1
VALUES
    (default, NULL, NULL);

INSERT INTO
    test_table_1
VALUES
    (default, 'a', 'b');


DROP TABLE IF EXISTS test_table_1;


-- Adding the NOT NULL constraint to the existing column.
CREATE TABLE test_table_2 (
    id SERIAL PRIMARY KEY NOT NULL,
    column_1 CHAR(1)
);

ALTER TABLE
    test_table_2
ALTER COLUMN column_1 SET NOT NULL;


DROP TABLE IF EXISTS test_table_2;
