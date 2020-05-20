/*
    CREATE PROCEDURE — define a new procedure

    Synopsis
        CREATE [ OR REPLACE  ] PROCEDURE
            name ( [ [ argmode  ] [ argname  ] argtype [ { DEFAULT | =  } default_expr  ] [, ...]  ]  )
          { LANGUAGE lang_name
            | TRANSFORM { FOR TYPE type_name  } [, ... ]
            | [ EXTERNAL  ] SECURITY INVOKER | [ EXTERNAL  ] SECURITY DEFINER
            | SET configuration_parameter { TO value | = value | FROM CURRENT  }
            | AS 'definition'
            | AS 'obj_file', 'link_symbol'
          } ...

    PostgreSQL 11 introduced stored procedures that support transactions.

    Unlike a user-defined function, a stored procedure does not have a return value.
    To end a procedure earlier, use the RETURN statement with no expression:

    In case to return a value from a stored procedure, use output parameters.
    The final values of the output parameters will be returned to the caller.

    To call a stored procedure, use the CALL statement as follows:
        CALL stored_procedure_name(parameter_list);
*/

CREATE OR REPLACE PROCEDURE get_name (name VARCHAR)
LANGUAGE plpgsql AS
$$
    <<block>>
    BEGIN
        RAISE NOTICE 'name %', name;
    END block;
$$;

DROP PROCEDURE get_name;
