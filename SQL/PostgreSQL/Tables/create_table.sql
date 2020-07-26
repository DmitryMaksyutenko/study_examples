/*
    CREATE TABLE will create a new, initially empty table in the current database.
    The table will be owned by the user issuing the command.

    CREATE [ [ GLOBAL | LOCAL  ] { TEMPORARY | TEMP  } | UNLOGGED  ] TABLE [ IF NOT EXISTS  ]
    table_name ( [
      { column_name data_type [ COLLATE collation  ] [ column_constraint [ ...  ]  ]
          | table_constraint
          | LIKE source_table [ like_option ...  ] }
          [, ... ] ] )

      [ INHERITS ( parent_table [, ... ]  )  ]
      [ PARTITION BY { RANGE | LIST | HASH  } ( { column_name | ( expression  )  }
        [ COLLATE collation  ] [ opclass  ] [, ... ]  )  ]
      [ USING method  ]
      [ WITH ( storage_parameter [= value] [, ... ]  ) | WITHOUT OIDS  ]
      [ ON COMMIT { PRESERVE ROWS | DELETE ROWS | DROP  }  ]
      [ TABLESPACE tablespace_name  ]

    Constraints
    PostgreSQL includes the following column constraints:

    NOT NULL – ensures that values in a column cannot be NULL.

    UNIQUE – ensures the values in a column unique across the rows within the same table.

    PRIMARY KEY – a primary key column uniquely identify rows in a table.
    A table can have one and only one primary key. The primary key constraint allows to define
    the primary key of a table.

    CHECK – a CHECK constraint ensures the data must satisfy a boolean expression.

    FOREIGN KEY – ensures values in a column or a group of columns from a table exists in
    a column or group of columns in another table. Unlike the primary key, a table can have
    many foreign keys.

    Table constraints are similar to column constraints except that they are applied
    to more than one column.
*/

CREATE TABLE test_table();
DROP TABLE test_table;

CREATE TABLE accounts (
  user_id SERIAL PRIMARY KEY,
  user_name VARCHAR (50) NOT NULL,
  password VARCHAR (50) NOT NULL,
  email VARCHAR (255) UNIQUE NOT NULL,
  created TIMESTAMP NOT NULL,
  last_login TIMESTAMP NOT NULL
);

CREATE TABLE roles (
  role_id SERIAL PRIMARY KEY,
  role_name VARCHAR (50) NOT NULL
);

CREATE TABLE account_role (
  account_id INT NOT NULL,
  role_id INT NOT NULL,
  grant_date TIMESTAMP,
  PRIMARY KEY (account_id, role_id),
  FOREIGN KEY (role_id) REFERENCES roles (role_id),
  FOREIGN KEY (account_id) REFERENCES accounts (user_id)
);

DROP TABLE IF EXISTS accounts;
DROP TABLE IF EXISTS roles;
DROP TABLE IF EXISTS account_role;
