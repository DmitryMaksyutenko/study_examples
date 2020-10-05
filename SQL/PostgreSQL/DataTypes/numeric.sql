/*
    The NUMERIC type can store the numbers with a lot of digits.

    Typically the NUMERIC type used for storing the numbers that require exacts of monetary amounts or quantities.

        NUMERIC(precision, scale)
            The precision is the total numbers count.
            The scale is the count of numbers in the fraction par

            The scale of the NUMERIC can be zero.

    In PostgreSQL, the NUMERIC and  DECIMAL are equivalent and the part of the SQL standard.

    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    If precision is not required, don't use the NUMERIC, because the calculation for NUMERIC is slower than for
    INTEGER, FLOAT, DOUBLE PRECISION
*/

CREATE TABLE test_numeric (
    num_1 NUMERIC NOT NULL,
    num_2 NUMERIC(2, 2) NOT NULL,
    num_3 NUMERIC(8, 6) DEFAULT 'NaN'
);

-- Truncates the scale part in num_2 and num_3.
INSERT INTO
    test_numeric
VALUES
    (12341234123412341236465623461243.1234324123412341324, 0.123456, 12.2222221111);

-- Insert the NaN in to num_3.
INSERT INTO
    test_numeric
VALUES
    (12341234123412341236465623461243.1234324123412341324, 0.16);

-- Error. Numeric field overflow.
INSERT INTO
    test_numeric
VALUES
    (12341234123412341236465623461243.1234324123412341324, 1.16);


DROP TABLE IF EXISTS test_numeric;
