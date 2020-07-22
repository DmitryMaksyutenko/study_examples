/*
    To get the size of the specific  table, use the "pg_relation_size()" function.

    To make the result more human-readable, use the "pg_size_pretty()" function.

    To get the total size of the table, use the pg_total_relation_size() function.

    To get the size of the whole database, use the "pg_database_size()" function.

    To get total size of all indexes attached to a table, use "the pg_indexes_size()" function.

      The pg_indexes_size() function accepts the OID or table name as the argument
      and returns the total disk space used by all indexes attached of that table.

    To get the size of a tablespace, use the "pg_tablespace_size()" function.

    To find how much space needs to store a specific value, use the "pg_column_size()".
*/

SELECT pg_relation_size('actor');

SELECT pg_size_pretty(pg_relation_size('actor'));

SELECT pg_size_pretty(pg_total_relation_size('actor'));

SELECT pg_size_pretty(pg_database_size('dvdrental'));

SELECT pg_size_pretty(pg_indexes_size('actor'));

SELECT pg_size_pretty(pg_tablespace_size('pg_default'));

SELECT pg_column_size(5::int);
SELECT pg_column_size('some text for the size difining.'::text);
