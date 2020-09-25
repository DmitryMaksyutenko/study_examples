/*
     A CHECK constraint is a kind of constraint that allows to specify if values in a column must meet a specific requirement.

    The CHECK constraint uses a Boolean expression to evaluate the values before they are inserted or updated to the column.

    If the values pass the check, PostgreSQL will insert or update these values to the column.
    Otherwise, PostgreSQL will reject the changes and issue a constraint violation error.
*/


-- Create table with check constraint.
CREATE TABLE test_table (
    id SERIAL PRIMARY KEY NOT NULL,
    some_column_1 INT CHECK (some_column_1 > 0),
    some_clumn_2 CHAR CHECK (some_clumn_2 <> 'A'),
    some_clumn_3 DATE CHECK (some_clumn_3 > '2020-09-01')
);

-- Date error.
INSERT INTO
    test_table
VALUES
    (default, 1, 'a', '2020-08-01');

-- Character error.
INSERT INTO
    test_table
VALUES
    (default, 1, 'A', '2020-10-01');

-- Integer error.
INSERT INTO
    test_table
VALUES
    (default, -1, 'B', '2021-08-01');

-- All columns error.
INSERT INTO
    test_table
VALUES
    (default, 0, 'A', '2020-01-01');

-- Success.
INSERT INTO
    test_table
VALUES
    (default, 12, 'D', '2021-02-01');


DROP TABLE IF EXISTS test_table;


-- Create table without check constraint. Add constraint after.

CREATE TABLE test_table_1 (
    id SERIAL PRIMARY KEY NOT NULL,
    column_1 INT NOT NULL,
    column_2 CHAR NOT NULL,
    column_3 DATE NOT NULL
);


ALTER TABLE
    test_table_1
ADD CONSTRAINT
    column_constraint
CHECK
(
    column_1 > 0
    AND
    column_2 > 'a'
    AND
    column_3 > '1900-01-01'
);


DROP TABLE IF EXISTS test_table_1;
