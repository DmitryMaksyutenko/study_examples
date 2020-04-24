/*
  CREATE RULE defines a new rule appluing to a speciffied table or view.

  The PostgreSQL rule system allows one to define an alternative action to be performed on insertions,
  updates, or deletions tables.
  Roughly speaking, a rule causes additional commands execution when a given command on a given table is executed.

  Its important to realize that rule is really a command transformation mechanism, or command macro.
  The transformation happens before the execution of the command starts.

  CREATE [ OR REPLACE ] RULE name AS ON event
    TO table_name [ WHERE condition ]
    DO [ ALSO | INSTEAD ] { NOTHING | command | ( command; command ... ) }

  where event:
    SELECT | INSERT | UPDATE | DELETE

  DROP RULE [ IF EXISTS ] name ON table_name [ CASCADE | RESTRICT ]
*/

CREATE RULE counter_update AS ON INSERT
  TO account
  DO ALSO
    SELECT
      count(account_id) AS ids
    FROM
      account;

-- Shows the id count with insertion.
INSERT INTO
  account
  VALUES(
    default,
    'Somenewname',
    'Newsurname',
    'new@mail.com',
    'password1234'
  );

DROP RULE counter_update ON account;
