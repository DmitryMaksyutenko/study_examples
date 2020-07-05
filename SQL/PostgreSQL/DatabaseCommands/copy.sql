/*
    Copy a PostgreSQL database within a database server for testing purposes.

        CREATE DATABASE target_db
        WITH TEMPLATE source_db;

    PostgreSQL copy database from a server to another:

        There are several ways to copy a database between PostgreSQL database servers.
        If the size of the source database is big and the connection between the database
        servers is slow, dump the source database to a file, copy the file to the remote
        server, and restore it.

        pg_dump -U postgres -O sourcedb sourcedb.sql

        Create a new database in the remote server:

            CREATE DATABASE targetdb;

        Restore the dvdrental.sql dump file in the remote server:

            psql -U postgres -d dvdrental -f dvdrental.sql
*/


CREATE DATABASE new_dvdrental
WITH TEMPLATE dvdrental;

DROP DATABASE IF EXISTS new_dvdrental;
