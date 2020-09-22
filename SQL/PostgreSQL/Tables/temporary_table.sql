/*
    A temporary table, as its named implied, is a short-lived table that exists for the duration of a database session.
    PostgreSQL automatically drops the temporary tables at the end of a session or a transaction.

    To create a temporary table, use the CREATE TEMPORARY TABLE statement:

        CREATE TEMPORARY TABLE temp_table_name (
            column_list
            ...
        );

    A temporary table is visible only to the session that creates it. In other words, it is invisible to other sessions.
*/

CREATE TEMPORARY TABLE test_tmp (
    id INT,
    some_field DATE
);
