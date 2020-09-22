/*
    To remove all data from a table, use the DELETE statement. However, when use the DELETE statement to delete all data from a table
    that has a lot of data, it is not efficient. In this case, use the TRUNCATE TABLE statement:

        TRUNCATE TABLE table_name;

    The  TRUNCATE TABLE statement deletes all data from a table without scanning it. This is the reason why it is faster than the DELETE statement.

    In addition, the TRUNCATE TABLE statement reclaims the storage right away so it is do not need to perform a subsequent VACUMM operation,
    which is useful in the case of large tables.

    To remove data from a table and other tables that have foreign key reference the table, use CASCADE option in the TRUNCATE TABLE statement:

        TRUNCATE TABLE table_name
        CASCADE;

    Besides removing data, it's possible to reset the values in the identity column by using the RESTART IDENTITY option like this:

        TRUNCATE TABLE table_name
        RESTART IDENTITY;
*/

CREATE TABLE person (
    id SERIAL PRIMARY KEY NOT NULL,
    name VARCHAR(40) NOT NULL
);


INSERT INTO person
VALUES
(default, (
            CHR(GENERATE_SERIES(1, 1000)) ||
            CHR(GENERATE_SERIES(1, 1000))
          )
);


TRUNCATE TABLE person
RESTART IDENTITY;


DROP TABLE person;
