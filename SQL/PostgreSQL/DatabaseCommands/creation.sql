/*
    CREATE DATABASE db_name
    OWNER =  role_name
    TEMPLATE = template
    ENCODING = encoding
    LC_COLLATE = collate
    LC_CTYPE = ctype
    TABLESPACE = tablespace_name
    CONNECTION LIMIT = max_concurrent_connection

    db_name: is the name of the new database to create. The database name must be unique
        in the PostgreSQL database server. If try to create a new database that has the
        same name as an existing database, PostgreSQL will issue an error.

    role_name: is the role name of the user who will own the new database.
        PostgreSQL uses user’s role name who executes the CREATE DATABASE statement
        as the default role name.

    template: is the name of the database template from which the new database creates.
        PostgreSQL allows to create a database based on a template database.
        The template1 is the default template database.

    encoding: specifies the character set encoding for the new database.
        By default, it is the encoding of the template database.

    collate: specifies a collation for the new database. The collation specifies
        the sort order of strings that affect the result of the ORDER BY clause in the
        SELECT statement. The template database’s collation is the default collation
        for the new database if not specifyed it explicitly in the LC_COLLATE parameter.

    ctype: specifies the character classification for the new database.
        The ctype affects the categorization e.g., digit, lower and upper.
        The default is the character classification of the template database.

    tablespace_name: specifies the tablespace name for the new database.
        The default is the template database’s tablespace.

    max_concurrent_connection: specifies the maximum concurrent connections to the new database.
        The default is -1 i.e., unlimited. This feature is very useful in the shared hosting
        environments where can be configured the maximum concurrent connections for
        a particular database.
*/

CREATE DATABASE test_db
OWNER = postgres
TEMPLATE = template1
ENCODING = 'LATIN9'
ONNECTION_LIMIT = 12;

DROP DATABASE test_db;
