/*
    Functions written in PL/pgSQL are defined to the server by executing CREATE FUNCTION commands.
    User-defined functions cannot execute transactions. In other words, inside a function cannot
    open a new transaction, even commit or rollback the current transaction. Use the procedure insted.

    CREATE [ OR REPLACE  ] FUNCTION
        name ( [ [ argmode  ] [ argname  ] argtype [ { DEFAULT | =  } default_expr  ] [, ...]  ]  )
            [ RETURNS rettype | RETURNS TABLE ( column_name column_type [, ...]  ) ]
        { LANGUAGE lang_name
            | TRANSFORM { FOR TYPE type_name  } [, ... ]
            | WINDOW
            | IMMUTABLE | STABLE | VOLATILE | [ NOT  ] LEAKPROOF
            | CALLED ON NULL INPUT | RETURNS NULL ON NULL INPUT | STRICT
            | [ EXTERNAL  ] SECURITY INVOKER | [ EXTERNAL  ] SECURITY DEFINER
            | PARALLEL { UNSAFE | RESTRICTED | SAFE  }
            | COST execution_cost
            | ROWS result_rows
            | SUPPORT support_function
            | SET configuration_parameter { TO value | = value | FROM CURRENT  }
            | AS 'definition'
            | AS 'obj_file', 'link_symbol'
        } ...

    PL/pgSQL is a block-structured language. The complete text of a function body must be a block.
    A block is defined as:

        [ <<label>>  ]
        [ DECLARE declarations ]
            BEGIN
                statements
            END [ label  ];

    DO statement does not belong to the block. It is used to execute an anonymous block.

    The double dollar ($$) is a substitution of a single quote (‘).
    When develop a PL/pgSQL block, a function, or a stored procedure, locate the body in the
    form of a string literal.

    The syntax of declaring a variable:
        variable_name data_type [:= expression];

    To declare a constant in PL/pgSQL, use the following syntax:
        constant_name CONSTANT data_type [:= expression]

    To raise a message, use the RAISE statement as follows:
        RAISE level format;
            level:
                DEBUG
                LOG
                NOTICE
                INFO
                WARNING
                EXCEPTION
            The format is a string that specifies the message.
            The format uses percentage ( % ) placeholders that will be substituted by the next arguments.

            To raise errors, use the EXCEPTION level after the RAISE statement.
            RAISE statement uses the EXCEPTION level by default.

    The ASSERT statement:
        ASSERT condition [, message];
*/


DO $$
    <<first_block>>
    DECLARE
      counter integer := 0;
    BEGIN 
           counter := counter + 1;
           RAISE NOTICE 'The current value of counter is %', counter;
    END first_block $$;


DO $$
    <<outer_block>>
    DECLARE
      counter integer := 0;
    BEGIN
       counter := counter + 1;
       RAISE NOTICE 'The current value of counter is %', counter;
       DECLARE
           counter integer := 0;
           BEGIN
               counter := counter + 10;
               RAISE NOTICE 'The current value of counter in the subblock is %', counter;
               RAISE NOTICE 'The current value of counter in the outer block is %', outer_block.counter;
           END;
           RAISE NOTICE 'The current value of counter in the outer block is %', counter;
END outer_block $$;


CREATE FUNCTION foo(lhs integer, rhs integer)
RETURNS integer AS $$
<<block>>
    BEGIN
        RETURN lhs + rhs;
    END block;
$$
LANGUAGE plpgsql;

DROP FUNCTION foo;


CREATE FUNCTION fact(val INTEGER)
RETURNS INTEGER AS $$
    <<block>>
    DECLARE
        result INTEGER := 0;
        curr INTEGER := 0;
        prev INTEGER := 1;
    BEGIN
        FOR i IN 1 .. val LOOP
            curr = i;
            result = prev * curr;
            prev = result;
        END LOOP;
    RETURN result;
    END block;
$$
LANGUAGE plpgsql;

DROP FUNCTION fact;


-- Function returns table. Table function.
CREATE OR REPLACE FUNCTION get_years (lhs INT, rhs INT)
RETURNS TABLE (
    id INT,
    some_date DATE
    ) AS $$
    <<block>>
    BEGIN
        FOR val IN lhs .. rhs LOOP
            id = val;
            some_date = FORMAT('201%s-0%s-%s', val::CHAR, val::CHAR, val::CHAR);
            RETURN NEXT;
        END LOOP;
    END block;
$$
LANGUAGE plpgsql;

DROP FUNCTION IF EXISTS get_years(INT, INT);


-- Generate series.
SELECT * FROM generate_series(0, 10);
SELECT * FROM generate_series(0, 10, 2);


-- Function returns multiple rows.
CREATE OR REPLACE FUNCTION get_all(val VARCHAR(10))
RETURNS SETOF actor AS $$
    BEGIN
        RETURN QUERY
        SELECT
            *
        FROM
            actor
        WHERE
            first_name LIKE FORMAT('%s%%', val);
    END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION get_names(val VARCHAR(10))
RETURNS TABLE (first_name VARCHAR(50)) AS $$
    BEGIN
        RETURN QUERY
        SELECT
            actor.first_name
        FROM
            actor
        WHERE
            actor.first_name LIKE FORMAT('%s%%', val);
    END;
$$ LANGUAGE plpgsql;

DROP FUNCTION IF EXISTS get_names(VARCHAR(10));
DROP FUNCTION IF EXISTS get_all(VARCHAR(10));
