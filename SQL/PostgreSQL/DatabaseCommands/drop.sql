/*
    DROP DATABASE [IF EXISTS] name;

        Specify the name of the database that want to delete after the DROP DATABASE clause.
        IF EXISTS prevent an error from removing a non-existent database.
*/

CREATE DATABASE hrdb;
CREATE DATABASE testdb1;

DROP DATABASE IF EXISTS hrdb;

SELECT
    *
FROM
    pg_stat_activity
WHERE
    datname = 'testdb1';

SELECT
    pg_terminate_backend (pg_stat_activity.pid)
FROM
    pg_stat_activity
WHERE
    pg_stat_activity.datname = 'testdb1';

DROP DATABASE testdb1;
