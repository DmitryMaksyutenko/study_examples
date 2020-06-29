/*
    Disconnect from the database that must be renamed.
    Check and terminate all active connections to the database that is being renamed.
    Use the ALTER DATABASE statement to rename the database to the new one.
*/

CREATE DATABASE test_db;

-- Check active connections with databese.
SELECT
    *
FROM
    pg_stat_activity
WHERE
    datname = 'test_db';

-- Terminate all active connections.
SELECT
    pg_terminate_backend (pid)
FROM
    pg_stat_activity
WHERE
    datname = 'test_db';

-- Database renaming.
ALTER DATABASE test_db RENAME TO newdb;

DROP DATABASE IF EXISTS newdb;
