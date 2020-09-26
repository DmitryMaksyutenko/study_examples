/*
    The unique constraint is used for ensuring that a column or a set of columns doesn't repeat across relation.

    When a unique constraint is assigned to a column or columns, it rejects the insertion of a new row, and raise an error message.

    When a unique constraint added to a column or a columns, the PostgreSQL automatically creates the unique index for that column/columns.
*/


-- One unique column.
CREATE TABLE test_table_1 (
    id SERIAL PRIMARY KEY NOT NULL,
    unique_col CHAR(6) UNIQUE
);


INSERT INTO
    test_table_1
VALUES
    (default, 'a');

--Causes an error.
INSERT INTO
    test_table_1
VALUES
    (default, 'a');


DROP TABLE IF EXISTS test_table_1;


-- Multiple uniqie columns.
CREATE TABLE test_table_2 (
    id SERIAL PRIMARY KEY NOT NULL,
    unique_col_1 CHAR(1),
    unique_col_2 CHAR(1),
    UNIQUE (unique_col_1, unique_col_2)
);


INSERT INTO
    test_table_2
VALUES
    (default, 'a', 'A'),
    (default, 'b', 'B');

-- No errors.
INSERT INTO
    test_table_2
VALUES
    (default, 'a', 'b');

-- Change the constraint.
TRUNCATE TABLE test_table_2
RESTART IDENTITY;

ALTER TABLE test_table_1
DROP CONSTRAINT test_table_2_unique_col_1_unique_col_2_key;

-- Creating the new unique index.
CREATE UNIQUE INDEX CONCURRENTLY test_table_2_col_1
ON test_table_2 (unique_col_1);

ALTER TABLE test_table_2
ADD CONSTRAINT test_table_2_col_1
UNIQUE USING INDEX test_table_2_col_1;

CREATE UNIQUE INDEX test_table_2_col_2
ON test_table_2 (unique_col_2);

ALTER TABLE test_table_2
ADD CONSTRAINT test_table_2_col_2
UNIQUE USING INDEX test_table_2_col_2;

-- Retrying the insertion.
INSERT INTO
    test_table_2
VALUES
    (default, 'a', 'A'),
    (default, 'b', 'B');

-- Cause the error.
INSERT INTO
    test_table_2
VALUES
    (default, 'a', 'b');


DROP TABLE IF EXISTS test_table_2;
