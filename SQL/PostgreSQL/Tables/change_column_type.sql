/*
  ALTER TABLE table_name
  ALTER COLUMN column_name [SET DATA] TYPE new_data_type;

  First, specify the name of the table to which the column want to change after the ALTER TABLE keywords.
  Second, specify the name of the column that want to change the data type after the ALTER COLUMN clause.
  Third, supply the new data type for the column after the TYPE keyword. The SET DATA TYPE and TYPE are equivalent.

  To change the data types of multiple columns in a single statement, use multiple ALTER COLUMN clauses:

    ALTER TABLE table_name
    ALTER COLUMN column_name1 [SET DATA] TYPE new_data_type,
    ALTER COLUMN column_name2 [SET DATA] TYPE new_data_type,
    ...;
*/

CREATE TABLE post (
  id SERIAL PRIMARY KEY NOT NULL,
  author VARCHAR NOT NULL,
  context VARCHAR NOT NULL,
  date_of DATE NOT NULL
);


INSERT INTO
  post
VALUES
  (default, 'Some Author', 'context.', CURRENT_DATE),
  (default, 'Some Author', ' bla bla context.', CURRENT_DATE),
  (default, 'Some Author', 'bla la bla context.', CURRENT_DATE),
  (default, 'Some Author', 'bla bla bla context bla bla bla context.', CURRENT_DATE),
  (default, 'Some Author', 'bla bla bla context.', CURRENT_DATE),
  (default, 'Some Author', 'bla bla bla context.', CURRENT_DATE),
  (default, 'Some Author', 'bla bla bla context.', CURRENT_DATE),
  (default, 'Some Author', 'bla bla bla context.', CURRENT_DATE),
  (default, 'Some Author', 'bla bla bla context.', CURRENT_DATE);


ALTER TABLE post
ALTER COLUMN context TYPE TEXT;


DROP TABLE IF EXISTS post;
