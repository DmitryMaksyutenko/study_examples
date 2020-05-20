/*
    Functions written in PL/pgSQL are defined to the server by executing CREATE FUNCTION commands.
    User-defined functions is that they cannot execute transactions.
    In other words, inside a function cannot open a new transaction, even commit or rollback the
    current transaction. Use the procedure insted.


        CREATE FUNCTION somefunc(integer, text) RETURNS integer
        AS 'function body text'
        LANGUAGE plpgsql;

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

    To raise a message, you use the RAISE statement as follows:
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


CREATE FUNCTION foo(lhs integer, rhs integer) RETURNS integer AS
$$
<<block>>
    BEGIN
        RETURN lhs + rhs;
    END block;
$$
LANGUAGE plpgsql;

DROP FUNCTION foo;


CREATE FUNCTION fact(val INTEGER) RETURNS INTEGER AS
$$
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
