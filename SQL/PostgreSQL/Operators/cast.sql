/*
    The CAST  operator converts a value of one data type to another.

        CAST(expression AS target_type) 
*/

-- Determine the data type. Convert string to integer.
SELECT pg_typeof(CAST('1000' AS INT));

-- Convert string to double.
SELECT CAST('12.07' AS DOUBLE PRECISION);
SELECT CAST('12.07' AS FLOAT);

-- Convert string to double.
SELECT CAST(12.07 AS FLOAT);

-- Convert string to a date.
SELECT CAST('2020-12-31' AS DATE);

-- Convert in to bool.
SELECT CAST('yes' AS BOOLEAN);
SELECT CAST('t' AS BOOLEAN);
SELECT CAST('F' AS BOOLEAN);
SELECT CAST(0 AS BOOLEAN);
SELECT CAST(10 AS BOOLEAN);