/*
  CREATE TABLESPACE registers a new cluster-wide tablespace.
  The tablespace name must be distinct from the name of
  any existing tablespace in the database cluster.

  REATE TABLESPACE tablespace_name
    [ OWNER { new_owner | CURRENT_USER | SESSION_USER  }  ]
    LOCATION 'directory'
    [ WITH ( tablespace_option = value [, ... ]  )  ]

  By default, the user who executed the CREATE TABLESPACE is the owner of the tablespace.

  When create a tablespace in UNIX systems, a permission error may occur even 777 permission
  granted to the tablespace directory. To fix this issue, changethe owner of the data directory
  to postgresuser by using the chwoncommand as the following:
    chown postgres /usr/data/tablespace_dir
*/

CREATE TABLESPACE test_tablespace LOCATION '/full/path/to/tablespace';
