/*
  A trigger is a speciffication that the database should automatically execute
  a particular function whenever a certain type of operation performed.
  Trigger can be attached to tables, views, and foreign tables.

  On tables and foreign tables, triggers can be defined to execute either before
  or after any INSERT, UPDATE, DELETE operation, either once per modified row, or
  once per SQL statement.

  On views, triggers can be difined to execute insted of INSERT, UPDATE, DELETE
  poerations.

  A Trigger is a cpecial user-defined function associated with a table. To create a new
  trigger, first create a trigger function and then bind this trigger function to a table.
  It will be automatically invoked when an event occurs.

  CREATE [ CONSTRAINT ] TRIGGER name { BEFORE | AFTER | INSTEAD OF } { event [ OR ... ] }
    ON table_name
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
*/


-- Creating tables for a triggers tests.
CREATE TABLE employees(
  id SERIAL PRIMARY KEY,
  first_name VARCHAR(40) NOT NULL,
  last_name VARCHAR(40) NOT NULL
);

CREATE TABLE employee_audits (
  id SERIAL PRIMARY KEY,
  empoyee_id INT NOT NULL,
  last_name VARCHAR(40) NOT NULL,
  changed_on TIMESTAMP(6) NOT NULL
);

-- A Trigger function doesn't take any argument and has a return value with a
-- type of trigger.
CREATE OR REPLACE FUNCTION log_last_name_changes()
  RETURNS trigger AS
$BODY$
BEGIN
  IF NEW.last_name <> OLD.last_name
  THEN
    INSERT INTO employee_audits(empoyee_id, last_name, changed_on)
    VALUES (OLD.id, OLD.last_name, now());
  END IF;
  RETURN NEW;
END
$BODY$
LANGUAGE 'plpgsql';


-- Creating the trigger.
CREATE TRIGGER last_name_changes
  BEFORE UPDATE
  ON employees
  FOR EACH ROW
  EXECUTE PROCEDURE log_last_name_changes();

-- Testins.
INSERT INTO employees(first_name, last_name)
VALUES ('Name1', 'Surname1');

INSERT INTO employees(first_name, last_name)
VALUES ('Name2', 'Surname2');

UPDATE employees
SET last_name = 'Holms'
WHERE
 id = 2;

SELECT * FROM employees;

SELECT * FROM employee_audits;

-- Cleanup.
DROP TABLE employees;
DROP TABLE employee_audits;
DROP FUNCTION log_last_name_changes;
