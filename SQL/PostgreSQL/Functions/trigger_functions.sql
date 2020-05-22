/*
    A trigger is a speciffication that the database should automatically execute
    a particular function whenever a certain type of operation performed.
    Trigger can be attached to tables, views, and foreign tables.

    The difference between a trigger and a user-defined function is that a trigger
    is automatically invoked when an event occurs.

    On tables and foreign tables, triggers can be defined to execute either before
    or after any INSERT, UPDATE, DELETE operation, either once per modified row, or
    once per SQL statement.

    On views, triggers can be difined to execute insted of INSERT, UPDATE, DELETE
    poerations.

    A Trigger is a cpecial user-defined function associated with a table. To create a new
    trigger, first create a trigger function and then bind this trigger function to a table.
    It will be automatically invoked when an event occurs.

    PostgreSQL provides two main types of triggers: row and statement-level triggers.
    The differences between the two kinds are how many times the trigger is invoked
    and at what time. For example, if an UPDATE statement that affects 20 rows, the
    row-level trigger will be invoked 20 times, while the statement level trigger
    will be invoked 1 time.

    CREATE [ CONSTRAINT ] TRIGGER name { BEFORE | AFTER | INSTEAD OF } { event [ OR ... ] } ON table_name
        [ FROM referenced_table_name ]
        [ NOT DEFERRABLE | [ DEFERRABLE ] [ INITIALLY IMMEDIATE | INITIALLY DEFERRED ] ]
        [ REFERENCING { { OLD | NEW } TABLE [ AS ] transaction_relation_name } [ ... ] ]
        [ FOR [ EACH ] { ROW | STATEMENT } ]
        [ WHEN ( condition ) ]
        EXECUTE { FUNCTION | PROCEDURE } function_name ( arguments )

    where event can be one of:
        INSERT
        UPDATE [ OF column_name [, ...] ]
        DELETE
        TRUNCATE

    Triggers are useful in case the database is accessed by various applications,
    and want to keep the cross-functionality within the database that runs automatically
    whenever the data of the table is modified.
*/


-- First, define a new function.
-- A trigger function is similar to an ordinary function. However, a trigger
-- function does not take any argument and has a return value with the type of
-- trigger.
CREATE OR REPLACE FUNCTION trigger_get_count()
    RETURNS trigger AS
$$
    <<block>>
    BEGIN
        RAISE INFO 'The modified is: %', OLD;
        RAISE INFO 'The updated is: %', NEW;
        RETURN NEW;
    END block;
$$
LANGUAGE 'plpgsql';

-- Second, bind the trigger function to the table.
CREATE TRIGGER get_id_count
    BEFORE UPDATE
    ON actor
    FOR EACH ROW
    EXECUTE PROCEDURE trigger_get_count();

-- Udate last updated time.
UPDATE actor
SET
    last_update = NOW()
WHERE
    actor_id = 1;

DROP TRIGGER get_id_count ON actor;
DROP FUNCTION trigger_get_count;
