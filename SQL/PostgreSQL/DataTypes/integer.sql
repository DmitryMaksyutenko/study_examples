/*
    Types described in file DataTypes/dataTypes.sql

    INTEGER is the most common data type for store the numbers values.
    It's the middle between performance and storage size.

    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    The PostgreSQL hasn't unsigned integer data types.
*/

CREATE TABLE integer_test (
    small_int SMALLINT NOT NULL CHECK(small_int >= 0), -- Unsigned.
    int_type INT NOT NULL,
    big_int BIGINT NOT NULL
);

-- Error. Check constraint.
INSERT INTO
    integer_test
VALUES
    (-1, 1234, 1235415212345);

-- No errors.
INSERT INTO
    integer_test
VALUES
    (12, -1234, 2346543);


DROP TABLE IF EXISTS integer_test;
