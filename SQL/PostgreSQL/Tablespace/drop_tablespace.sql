/*
    DROP TABLESPACE — remove a tablespace.

    DROP TABLESPACE [ IF EXISTS ] name;

    A tablespace can only be dropped by its owner or a superuser.
    The tablespace must be empty of all database objects before it can be dropped.
*/

DROP TABLESPACE IF EXISTS test_tablespace;
