/*
    Shows the value of the runtime parameter.
    These variables can be set using the SET statement.

    SHOW ALL;
    SHOW name;

        ALL - Show the values of all configuration parameters, with descriptions.

        name - The name of the runtime parameter.

    The parameters that can't be set:

        SERVER_VERSION - Shows the server's version number.

        SERVER_ENCODING - Shows the server-side character set encoding. At present, this parameter can be shown but not set,
                          because the encoding is determined at database creation time.

        LC_COLLATE - Shows the database's locale setting for collation (text ordering).
                     At present, this parameter can be shown but not set,
                     because the setting is determined at database creation time.

        LC_CTYPE - Shows the database's locale setting for character classification.
                   At present, this parameter can be shown but not set,
                   because the setting is determined at database creation time.

        IS_SUPERUSER - True if the current role has superuser privileges.

    The function current_setting() and the pg_settings system view produces equivalent output.
*/

SELECT current_setting('datestyle');

SHOW ALL;

SHOW max_connections;

SHOW autovacuum;
