/*
    ALTER DATABASE target_database action;

    ALTER DATABASE target_database RENAME TO new_database;

    ALTER DATABASE target_database OWNER TO new_onwer;

    ALTER DATABASE target_database SET TABLESPACE new_tablespace;

    ALTER DATABASE target_database SET configuration_parameter = value;
*/

CREATE DATABASE testdb2;

ALTER DATABASE testdb2 RENAME TO testhrdb;

ALTER DATABASE testhrdb OWNER TO test_user;

DROP DATABASE testhrdb;
