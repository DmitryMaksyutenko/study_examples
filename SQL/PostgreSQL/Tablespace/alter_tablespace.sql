/*
    ALTER TABLESPACE — change the definition of a tablespace.

    ALTER TABLESPACE name RENAME TO new_name
    ALTER TABLESPACE name OWNER TO { new_owner | CURRENT_USER | SESSION_USER  }
    ALTER TABLESPACE name SET ( tablespace_option = value [, ... ]  )
    ALTER TABLESPACE name RESET ( tablespace_option [, ... ]  )

tablespace_option:
    seq_page_cost.
    random_page_cost.
    effective_io_concurrency.
*/

-- Rename the tablespace.
ALTER TABLESPACE test_tablespace RENAME TO new_test_tablespace_name;
ALTER TABLESPACE new_test_tablespace_name RENAME TO test_tablespace;
